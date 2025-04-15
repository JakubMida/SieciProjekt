#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

enum class NetworkMode
{
    Local, Server, Client
};

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void setMode(NetworkMode mode);
    void connectToServer(QString address, int port);
    void disconectFrom();
    bool isClientConnected();

    bool startListening(int port);
    void stopListening();
    bool isServerRunning();
    bool isClientConnectedToServer();
    void initNetwork(NetworkMode mode);
    void setServerAddress(QString address);
    QString getServerAddress();

signals:
    void connected(QString address, int port); //client
    void disconecetd(); //client

private slots:
    void clientConnected();

    void slotNewClient();
    void slotClientDisconected();

private:
    QString serverAddress = "127.0.0.1";
    int clientPort = 12345;
    int serverPort = 12345;
    bool listening = false;

    NetworkMode mode = NetworkMode::Local;
    QTcpServer Server;
    QTcpSocket Client;
    QVector<QTcpSocket*> Clients;
};

#endif // NETWORK_H
