#include "network.h"
#include <QDebug>

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
void Network::wyslacWartoscSterowania(double wartosc) {
    if(isClientConnected()){
        QJsonObject pkt{{"wartoscSterowania", wartosc}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        Client.write(out);
        Client.flush();
        qDebug() << "wartoscSterowania wyslana: " + QString::number(wartosc);
    }
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
        if(obj.contains("command")){
            NetworkCommand cmd = static_cast<NetworkCommand>(obj["command"].toInt());
            int sample = obj["sample"].toInt();
            emit commandReceived(cmd, sample);
            continue;
        }
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
    }
}

void Network::sendCommand(NetworkCommand cmd, int sampleNumber)
{
    QJsonObject pkt{
        {"command", static_cast<int>(cmd)},
        {"sample", sampleNumber}
    };

    QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';

    if (mode == NetworkMode::Server) {
        for (QTcpSocket* client : Clients) {
            if (client->state() == QAbstractSocket::ConnectedState) {
                client->write(out);
                client->flush();
            }
        }
    } else {
        if (isClientConnected()) {
            Client.write(out);
            Client.flush();
        }
    }
}


