#include "network.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Network::Network(QObject *parent)
    : QObject{parent},
    Server(this),
    Client(this)
{
    connect(&Client, SIGNAL(connected()), this, SLOT(clientConnected()));
    connect(&Client, SIGNAL(disconnected()), this, SIGNAL(disconecetd()));

    connect(&Server, SIGNAL(newConnection()), this, SLOT(slotNewClient()));
    connect(&Client, &QTcpSocket::errorOccurred, this, [=](QAbstractSocket::SocketError socketError) {
        qDebug() << "[Client Error]" << Client.errorString();
        emit connectionFailed(Client.errorString());
    });
}

//client

void Network::setMode(NetworkMode m)
{
    mode = m;
}
NetworkMode Network::getMode(){
    return this->mode;
}
void Network::connectToServer(QString address, int port)
{
    serverAddress = address;
    clientPort = port;
    connect(&Client,&QTcpSocket::readyRead,this,&Network::daneGotowe);
    Client.connectToHost(serverAddress, port);
}

void Network::disconectFrom()
{

    if (Client.state() == QAbstractSocket::ConnectedState)
    {
        Client.close();
        qDebug() << "[Network] Client disconected";
    }
    else if( Client.state() == QAbstractSocket::ConnectingState)
    {
        Client.abort();
        qDebug() << "[Network] Client connection aborted";
    }
}

void Network::clientConnected()
{
    emit connected(serverAddress, clientPort);
    qDebug() << "[Network] Client connected";
}

//server

bool Network::startListening(int port)
{
    serverPort = port;
    listening = Server.listen(QHostAddress::Any, port);
    qDebug() << "[Network] Server is running";
    return listening;
}

void Network::stopListening()
{
    Server.close();
    listening = false;
}

void Network::slotNewClient() {
    QTcpSocket *client = Server.nextPendingConnection();
    Clients.push_back(client);
    auto addr = client->peerAddress().toString().replace("::ffff:", ""); // Remove "::ffff:" prefix
    qDebug() << "[Network] Client from: " << addr << " connected";
    emit clientConnectedFrom(addr);

    connect(client, &QTcpSocket::disconnected, this, &Network::slotClientDisconected);
    connect(client, &QTcpSocket::readyRead, this, [=]() {
        while (client->canReadLine()) {
            QByteArray line = client->readLine().trimmed();
            qDebug() << "[Network] Server received raw data:" << line;
            QJsonParseError err;
            QJsonDocument doc = QJsonDocument::fromJson(line, &err);
            if (err.error != QJsonParseError::NoError || !doc.isObject()) {
                qDebug() << "[Network] JSON parse error:" << err.errorString();
                continue;
            }
            QJsonObject obj = doc.object();
            if (obj.contains("wartoscSterowania")) {
                double u = obj["wartoscSterowania"].toDouble();
                emit wartoscSterowaniaOtrzymana(u);
            }
        }
    });
}

void Network::slotClientDisconected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if(client)
    {
        qDebug() <<"[Network] Client disconected from: " << client->peerAddress().toString();
        Clients.removeOne(client);
        client->deleteLater();
        emit clientDisconnected();
    }
}

bool Network::isServerRunning()
{
    return listening;
}

bool Network::isClientConnected()
{
    return (Client.state() == QAbstractSocket::ConnectedState);
}

bool Network::isSomebodyConnected()
{
    return !Clients.isEmpty();
}

void Network::wyslacWartoscRegulowania(double wartosc) {
    qDebug() << "Wyslac Wartosc Regulowania";
    if (mode == NetworkMode::Server) {
        // Server mode - send to all connected clients
        QJsonObject pkt{{"wartoscRegulowania", wartosc}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        for (QTcpSocket* client : Clients) {
            if (client->state() == QAbstractSocket::ConnectedState) {
                client->write(out);
                client->flush();
            }
        }
        qDebug() << "wartoscRegulowania sent to all clients: " + QString::number(wartosc);
    }
    else {
        // Client mode - send to server
        if (isClientConnected()) {
            QJsonObject pkt{{"wartoscRegulowania", wartosc}};
            QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
            Client.write(out);
            Client.flush();
            qDebug() << "wartoscRegulowania sent to server: " + QString::number(wartosc);
        }
    }
}

inline QJsonObject arxStanToJson(const arxStan& stan) {
    QJsonObject obj;
    QJsonArray A_array, B_array, wejscia_array, wyjscia_array;

    for (double a : stan.A) A_array.append(a);
    for (double b : stan.B) B_array.append(b);
    for (double w : stan.wejscia) wejscia_array.append(w);
    for (double y : stan.wyjscia) wyjscia_array.append(y);

    obj["A"] = A_array;
    obj["B"] = B_array;
    obj["opoznienie"] = stan.opoznienie;
    obj["zaklocenie"] = stan.zaklocenie;
    obj["wejscia"] = wejscia_array;
    obj["wyjscia"] = wyjscia_array;

    return obj;
}

void Network::wyslacStanArx(arxStan arxStan){
    QJsonObject obj;
    obj["arxSettings"] = arxStanToJson(arxStan);

    QByteArray data = QJsonDocument(obj).toJson(QJsonDocument::Compact) + '\n';

    if (mode == NetworkMode::Server) {
        for (QTcpSocket* client : Clients) {
            if (client->state() == QAbstractSocket::ConnectedState) {
                client->write(data);
                client->flush();
            }
        }
    } else if (mode == NetworkMode::Client && Client.state() == QAbstractSocket::ConnectedState) {
        Client.write(data);
        Client.flush();
    }

    qDebug() << "[Network] Sent arxStan";
}

void Network::wyslacWartoscSterowania(double wartosc) {
    if(isClientConnected()){
        QJsonObject pkt{{"wartoscSterowania", wartosc}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        Client.write(out);
        Client.flush();
        qDebug() << "wartoscSterowania wyslana: " + QString::number(wartosc);
    }
}


inline QJsonObject symulacjaStanToJson(const symulacjaStan& stan) {
    QJsonObject obj;

    obj["amplituda"] = stan.amplituda;
    obj["okres"] = stan.okres;
    obj["wypelnienie"] = stan.wypelnienie;
    obj["skladowaStala"] = stan.skladowaStala;
    obj["czasAktywacji"] = stan.czasAktywacji;
    obj["typ"] = static_cast<int>(stan.typ); // assuming TypSygnalu is enum

    obj["k"] = stan.k;
    obj["Ti"] = stan.Ti;
    obj["Td"] = stan.Td;
    obj["Uip"] = stan.Uip;
    obj["Uii"] = stan.Uii;
    obj["Uid"] = stan.Uid;
    obj["suma_uchybow"] = stan.suma_uchybow;
    obj["poprzedni_uchyb"] = stan.poprzedni_uchyb;
    obj["granicaDolna"] = stan.granicaDolna;
    obj["granicaGorna"] = stan.granicaGorna;
    obj["filtr"] = static_cast<int>(stan.filtr); // enum
    obj["tryb"] = static_cast<int>(stan.tryb);   // enum

    obj["poprzednie_wyjscie"] = stan.poprzednie_wyjscie;
    obj["sygnal"] = stan.sygnal;
    obj["uchyb"] = stan.uchyb;

    obj["krokCzasowy"] = stan.krokCzasowy;
    obj["czasSymulacji"] = stan.czasSymulacji;
    obj["uruchomiona"] = stan.uruchomiona;
    obj["wartosc"] = stan.wartosc;

    return obj;
}
void Network::wyslacStanSymulacji(symulacjaStan symStan){
    QJsonObject obj;
    obj["symulacjaStan"] = symulacjaStanToJson(symStan);

    QByteArray data = QJsonDocument(obj).toJson(QJsonDocument::Compact) + '\n';

    if (mode == NetworkMode::Server) {
        for (QTcpSocket* client : Clients) {
            if (client->state() == QAbstractSocket::ConnectedState) {
                client->write(data);
                client->flush();
            }
        }
    } else if (mode == NetworkMode::Client && Client.state() == QAbstractSocket::ConnectedState) {
        Client.write(data);
        Client.flush();
    }

    qDebug() << "[Network] Sent symulacjaStan";
}

inline std::vector<double> jsonArrayToVector(const QJsonArray& arr) {
    std::vector<double> vec;
    for (const auto& val : arr) vec.push_back(val.toDouble());
    return vec;
}

inline std::deque<double> jsonArrayToDeque(const QJsonArray& arr) {
    std::deque<double> dq;
    for (const auto& val : arr) dq.push_back(val.toDouble());
    return dq;
}

void Network::daneGotowe() {
    while (isClientConnected() && Client.canReadLine()) {
        QByteArray linia = Client.readLine().trimmed();
        qDebug() << "[Network] Otrzymane dane:" << linia;
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(linia, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject()) {
            qDebug() << "JSON parse error: " + err.errorString();
            continue;
        }
        QJsonObject obj = doc.object();
        if (obj.contains("wartoscSterowania")) {
            double u = obj["wartoscSterowania"].toDouble();
            qDebug() << "wartoscSterowania rec: " + QString::number(u);
            emit wartoscSterowaniaOtrzymana(u);
        }
        else if (obj.contains("wartoscRegulowania")) {
            double y = obj["wartoscRegulowania"].toDouble();
            qDebug() << "Measured rec: " + QString::number(y);
            emit wartoscRegulowaniaOtrzymana(y);
        }
        else if (obj.contains("typ")) {
            QString typ = obj["typ"].toString();

            if (typ == "arxStan") {
                arxStan stan;
                stan.A = jsonArrayToVector(obj["A"].toArray());
                stan.B = jsonArrayToVector(obj["B"].toArray());
                stan.opoznienie = obj["opoznienie"].toInt();
                stan.zaklocenie = obj["zaklocenie"].toDouble();
                stan.wejscia = jsonArrayToDeque(obj["wejscia"].toArray());
                stan.wyjscia = jsonArrayToDeque(obj["wyjscia"].toArray());

                emit stanArxOtrzymany(stan);
            }
            else if (typ == "symulacjaStan") {
                symulacjaStan stan;
                stan.amplituda = obj["amplituda"].toDouble();
                stan.okres = obj["okres"].toDouble();
                stan.wypelnienie = obj["wypelnienie"].toDouble();
                stan.skladowaStala = obj["skladowaStala"].toDouble();
                stan.czasAktywacji = obj["czasAktywacji"].toDouble();
                stan.typ = static_cast<TypSygnalu>(obj["typSygnalu"].toInt());

                stan.k = obj["k"].toDouble();
                stan.Ti = obj["Ti"].toDouble();
                stan.Td = obj["Td"].toDouble();
                stan.Uip = obj["Uip"].toDouble();
                stan.Uii = obj["Uii"].toDouble();
                stan.Uid = obj["Uid"].toDouble();
                stan.suma_uchybow = obj["suma_uchybow"].toDouble();
                stan.poprzedni_uchyb = obj["poprzedni_uchyb"].toDouble();
                stan.granicaDolna = obj["granicaDolna"].toDouble();
                stan.granicaGorna = obj["granicaGorna"].toDouble();
                stan.filtr = static_cast<Filtr>(obj["filtr"].toInt());
                stan.tryb = static_cast<TrybCalkowania>(obj["trybCalkowania"].toInt());

                stan.poprzednie_wyjscie = obj["poprzednie_wyjscie"].toDouble();
                stan.sygnal = obj["sygnal"].toDouble();
                stan.uchyb = obj["uchyb"].toDouble();

                stan.krokCzasowy = obj["krokCzasowy"].toDouble();
                stan.czasSymulacji = obj["czasSymulacji"].toDouble();
                stan.uruchomiona = obj["uruchomiona"].toBool();
                stan.wartosc = obj["wartosc"].toDouble();

                emit stanSymulacjiOtrzymany(stan);
            }
        }
    }
}

