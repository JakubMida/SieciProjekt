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

void Network::connectToServer(QString address, int port)
{
    serverAddress = address;
    clientPort = port;
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

void Network::slotNewClient()
{
    QTcpSocket * client = Server.nextPendingConnection();
    Clients.push_back(client);
    //auto addr = client->peerAddress().toString();
    auto addr = client->peerAddress().toString().replace("::ffff:", ""); //usunięci ffff z początku adresu
    qDebug() << "[Network] Client from: " << addr << " conected";
    emit clientConnectedFrom(addr);

    connect(client, SIGNAL(disconnected()),this, SLOT(slotClientDisconected()));
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


void Network::wyslacWartoscZmierzona(double wartosc)
{
    qDebug() << "Wyslac wartosc zmierzoną";
    if (isClientConnected()) {
        QJsonObject pkt{{"wartoscZmierzona", wartosc}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        Client.write(out);
        Client.flush();
        status = "wartoscZmierzona wyslana: " + QString::number(wartosc);
    }
}

void Network::wyslacWartoscSterowania(double wartosc)
{
    qDebug() << "Wyslac wartosc sterowania";
    if (isClientConnected()) {
        QJsonObject pkt{{"wartoscSterowania", wartosc}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        Client.write(out);
        Client.flush();
        status = "Control sent: " + QString::number(wartosc);
    }
}
void Network::daneGotowe(){
    while (isClientConnected() && Client.canReadLine()) {
        QByteArray line = Client.readLine().trimmed();
        qDebug() << "[Network] Otrzymana surowe dane:" << line;
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(line, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject()) {
            status = "JSON parse error: " + err.errorString();
            continue;
        }
        QJsonObject obj = doc.object();
        if (obj.contains("wartoscSterowania")) {
            double u = obj["wartoscSterowania"].toDouble();
            status = "wartoscSterowania rekord: " + QString::number(u);
            emit wartoscSterowaniaOtrzymana(u);
        }
        else if (obj.contains("wartoscZmierzona")) {
            double y = obj["wartoscZmierzona"].toDouble();
            status = "wartoscZmierzona rekord: " + QString::number(y);
            emit wartoscZmierzonaOtrzymana(y);
        }
    }
}
