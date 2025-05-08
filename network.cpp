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
    if (!Clients.isEmpty()) {
        QTcpSocket *client = Clients.first(); // Send to the first connected client
        if (client && client->state() == QAbstractSocket::ConnectedState) {
            QJsonObject pkt{{"wartoscZmierzona", wartosc}};
            QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
            client->write(out);
            client->flush();
            qDebug() << "[Network] Sent regulated value to client:" << wartosc;
        } else {
            qDebug() << "[Network] No active client to send regulated value.";
        }
    }
}
void Network::wyslacWartoscSterowania(double wartosc) {
    if (isClientConnected()) {
        QJsonObject pkt{{"wartoscSterowania", wartosc}};
        QByteArray out = QJsonDocument(pkt).toJson(QJsonDocument::Compact) + '\n';
        Client.write(out);
        Client.flush();
        qDebug() << "[Network] Sent control value to server:" << wartosc;
    } else {
        qDebug() << "[Network] Client not connected, cannot send control value.";
    }
}

void Network::daneGotowe() {
    while (isClientConnected() && Client.canReadLine()) {
        QByteArray line = Client.readLine().trimmed();
        qDebug() << "[Network] Client received raw data:" << line;
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(line, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject()) {
            qDebug() << "[Network] JSON parse error:" << err.errorString();
            continue;
        }
        QJsonObject obj = doc.object();
        if (obj.contains("wartoscZmierzona")) {
            double y = obj["wartoscZmierzona"].toDouble();
            emit wartoscRegulowaniaOtrzymana(y);
        }
    }
}
