#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QLineEdit>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>


enum class NetworkMode
{
    Server, Client
};

enum class NetworkCommand {
    Start,
    Stop,
    Step,
    Sync
};

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void setMode(NetworkMode mode);
    NetworkMode getMode();
    void connectToServer(QString address, int port);
    void disconectFrom();
    bool isClientConnected();

    bool startListening(int port);
    void stopListening();
    bool isServerRunning();
    bool isSomebodyConnected();


signals:
    void connected(QString address, int port); //client
    void disconecetd(); //client
    void connectionFailed(QString error);
    void clientConnectedFrom(QString address);
    void clientDisconnected();

    void wartoscSterowaniaOtrzymana(double wartosc);
    void wartoscRegulowaniaOtrzymana(double wartosc);

    void commandReceived(NetworkCommand cmd, int sampleNumber);

private slots:
    void clientConnected();
    void slotNewClient();
    void slotClientDisconected();

    void daneGotowe();
public slots:
    void wyslacWartoscRegulowania( double wartosc);
    void wyslacWartoscSterowania(double wartosc);

    void sendCommand(NetworkCommand cmd, int sampleNumber = 0);

private:
    QString serverAddress = "127.0.0.1";
    int clientPort = 12345;
    int serverPort = 12345;
    bool listening = false;

    NetworkMode mode;
    QTcpServer Server;
    QTcpSocket Client;
    QVector<QTcpSocket*> Clients;
    QString status;

    QTimer* syncTimer;
    int currentSampleNumber = 0;
};

#endif // NETWORK_H
