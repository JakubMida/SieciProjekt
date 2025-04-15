#include "oknosiec.h"
#include "ui_oknosiec.h"
#include <QMessageBox>

oknosiec::oknosiec(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::oknosiec)
{
    ui->setupUi(this);
    // Fix: create the network object
    network = new Network(this);

    // Now it's safe to connect signals
    connect(network, &Network::connected, this, [=](QString adr, int port) {
        qDebug() << "[Signal] Connected to" << adr << ":" << port;
        ui->lbl_message->setText(QString("Połączony z %1:%2").arg(adr).arg(port));
    });

    connect(network, &Network::disconecetd, this, [=]() {
        qDebug() << "[Signal] Disconnected";
        ui->lbl_message->setText("Odłączony");
    });

    connect(network, &Network::connectionFailed, this, [=](QString error){
        qDebug() << "Connection failed:" << error;

        QMessageBox::critical(this, "Błąd połączenia", "Nie można połączyć się z serwerem:\n" + error);
    });
}
oknosiec::~oknosiec()
{
    delete ui;
}

void oknosiec::trybSerwer()
{
    ui->txt_ip1->setEnabled(false);
    ui->txt_ip2->setEnabled(false);
    ui->txt_ip3->setEnabled(false);
    ui->txt_ip4->setEnabled(false);
    ui->btn_start_connect->setText("Start");
    ui->btn_stop_disconnect->setText("Stop");
    this->serwerMode = true;
}

void oknosiec::trybKlient()
{
    ui->txt_ip1->setEnabled(true);
    ui->txt_ip2->setEnabled(true);
    ui->txt_ip3->setEnabled(true);
    ui->txt_ip4->setEnabled(true);
    ui->btn_start_connect->setText("Podlącz");
    ui->btn_stop_disconnect->setText("Rozłącz");
    this->serwerMode = false;
}

void oknosiec::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        trybSerwer();
    }
    else{
        trybKlient();
    }
}

bool isValidIPSegment(const QString &segment) {
    bool ok;
    int value = segment.toInt(&ok);
    return ok && value >= 0 && value <= 255;
}

void oknosiec::on_btn_start_connect_clicked()
{
    setUIEnabled(false);
    int port = ui->txt_port->text().toInt();

    if (serwerMode) {
        qDebug() << "[Start] Server mode selected, initializing server on port" << port;
        inicializacjaSerwera(port);
        emit connectionStarted(serwerMode);
    }
    else
    {
        QString ip1 = ui->txt_ip1->text();
        QString ip2 = ui->txt_ip2->text();
        QString ip3 = ui->txt_ip3->text();
        QString ip4 = ui->txt_ip4->text();

        if (!isValidIPSegment(ip1) || !isValidIPSegment(ip2) ||
            !isValidIPSegment(ip3) || !isValidIPSegment(ip4)) {
            QMessageBox::warning(this, "Nieprawidłowy adres IP", "Wprowadź prawidłowy adres IP.");
            setUIEnabled(true);
            return;
        }

        QString ip = QString("%1.%2.%3.%4").arg(ip1).arg(ip2).arg(ip3).arg(ip4);

        qDebug() << "[Start] Client mode selected, connecting to" << ip << ":" << port;
        ui->lbl_message->setText(QString("Łączenie z %1:%2").arg(ip).arg(port));
        inicializacjaKlienta(ip, port);
        emit clientStarted();
    }
    //emit connectionStarted(serwerMode);

}


void oknosiec::on_btn_stop_disconnect_clicked()
{
    setUIEnabled(true);
    if (network->isClientConnected()) {
        network->disconectFrom();
        qDebug() << "[Stop] Client disconnected";
        ui->lbl_message->setText("Klient Odłączony");
    } else if (!serwerMode && network) {
        network->disconectFrom();
        qDebug() << "[Stop] Połączenie zostało przerwane";
        ui->lbl_message->setText("Połączenie zostało przerwane");
    }

    if (network->isServerRunning()) {
        network->stopListening();
        qDebug() << "[Stop] Server stopped";
         ui->lbl_message->setText("Serwer Wyłączony");
    }
    emit connectionStopped();
}

void oknosiec::inicializacjaSerwera(int port)
{
    network->setMode(NetworkMode::Server);

    if (network->isServerRunning()) {
        network->stopListening();
        qDebug() << "Server stopped before restarting";
    }

    if (!network->startListening(port)) {
        qDebug() << "Server failed to start on port:" << port;
        return;
    }

    qDebug() << "Server listening on port:" << port;
    ui->lbl_message->setText(QString("Serwer słucha na porcie %1").arg(port));

    disconnect(network, &Network::clientConnectedFrom, nullptr, nullptr);

    connect(network, &Network::clientConnectedFrom, this, [this](const QString &addr)
            {ui->lbl_message->setText(ui->lbl_message->text() + " | Klient: " + addr);});

    connect(network, &Network::clientDisconnected, this, [this, port]() {
        ui->lbl_message->setText(QString("Serwer słucha na porcie %1").arg(port));
    });

}
void oknosiec::inicializacjaKlienta(QString ip, int port)
{
    network->setMode(NetworkMode::Client);
    network->connectToServer(ip, port);
    qDebug() << "Client attempting to connect to" << ip << ":" << port;
}

void oknosiec::setUIEnabled(bool enabled)
{
    ui->comboBox->setEnabled(enabled);
    ui->txt_ip1->setEnabled(enabled && !serwerMode);
    ui->txt_ip2->setEnabled(enabled && !serwerMode);
    ui->txt_ip3->setEnabled(enabled && !serwerMode);
    ui->txt_ip4->setEnabled(enabled && !serwerMode);
    ui->txt_port->setEnabled(enabled);
    ui->btn_start_connect->setEnabled(enabled);
}


void oknosiec::closeEvent(QCloseEvent* event)
{
    event->ignore();
    this->hide();
}



