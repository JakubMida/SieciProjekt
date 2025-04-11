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
    Client.close();
    qDebug() << "Client disconected";
}

void Network::clientConnected()
{
    emit connected(serverAddress, clientPort);
    qDebug() << "Client connected";
}

//server

bool Network::startListening(int port)
{
    serverPort = port;
    listening = Server.listen(QHostAddress::Any, port);
    qDebug() << "Server is running";
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
    auto addr = client->peerAddress();

    connect(client, SIGNAL(disconnected()),this, SLOT(slotClientDisconected()));
}

bool Network::isServerRunning()
{
    return listening;
}

bool Network::isClientConnected()
{
    return (Client.state() == QAbstractSocket::ConnectedState);
}


