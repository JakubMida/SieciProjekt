#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

enum class NetworkMode
{
    Server, Client
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
    bool isSomebodyConnected();

    void sendData(const QByteArray& data);
    QByteArray reciveData();


signals:
    void connected(QString address, int port); //client
    void disconecetd(); //client
    void connectionFailed(QString error);
    void clientConnectedFrom(QString address);
    void clientDisconnected();
    void dataReceived(QByteArray data);

private slots:
    void clientConnected();
    void slotNewClient();
    void slotClientDisconected();

private:
    QString serverAddress = "127.0.0.1";
    int clientPort = 12345;
    int serverPort = 12345;
    bool listening = false;

    NetworkMode mode;
    QTcpServer Server;
    QTcpSocket Client;
    QVector<QTcpSocket*> Clients;
    QByteArray receivedData;
};

#endif // NETWORK_H
