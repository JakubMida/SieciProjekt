#include "oknosiec.h"
#include "ui_oknosiec.h"

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
        ui->lbl_message->setText(QString("Connected to %1:%2").arg(adr).arg(port));
    });

    connect(network, &Network::disconecetd, this, [=]() {
        qDebug() << "[Signal] Disconnected";
        ui->lbl_message->setText("Disconnected");
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


void oknosiec::on_btn_start_connect_clicked()
{
    int port = ui->txt_port->text().toInt();

    if (serwerMode) {
        qDebug() << "[Start] Server mode selected, initializing server on port" << port;
        inicializacjaSerwera(port);
    } else {
        QString ip = QString("%1.%2.%3.%4")
        .arg(ui->txt_ip1->text())
            .arg(ui->txt_ip2->text())
            .arg(ui->txt_ip3->text())
            .arg(ui->txt_ip4->text());

        qDebug() << "[Start] Client mode selected, connecting to" << ip << ":" << port;
        ui->lbl_message->setText(QString("Connecting to %1:%2").arg(ip).arg(port));
        inicializacjaKlienta(ip, port);
    }
}


void oknosiec::on_btn_stop_disconnect_clicked()
{
    if (network->isClientConnected()) {
        network->disconectFrom();
        qDebug() << "[Stop] Client disconnected";
        ui->lbl_message->setText("Client Disconnected");
    }

    if (network->isServerRunning()) {
        network->stopListening();
        qDebug() << "[Stop] Server stopped";
        ui->lbl_message->setText("Server Stopped");
    }
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
    ui->lbl_message->setText(QString("Server listening on port %1").arg(port));
}
void oknosiec::inicializacjaKlienta(QString ip, int port)
{
    network->setMode(NetworkMode::Client);
    network->connectToServer(ip, port);
    qDebug() << "Client attempting to connect to" << ip << ":" << port;
}

void oknosiec::closeEvent(QCloseEvent* event)
{
    event->ignore();
    this->hide();
}

