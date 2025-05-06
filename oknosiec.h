#ifndef oknosiec_H
#define oknosiec_H

#include <QDialog>
#include <QCloseEvent>
#include "network.h"
#include "arx.h"

namespace Ui {
class oknosiec;
}

class oknosiec : public QDialog
{
    Q_OBJECT

public:
    explicit oknosiec(QWidget *parent = nullptr);
    ~oknosiec();
    void trybSerwer();
    void trybKlient();
    void inicializacjaSerwera(int port);
    void inicializacjaKlienta(QString ip, int port);
    void setUIEnabled(bool enabled);
    void checkIfClientIsConnected();
    Network* getNetwork() const { return network; }
    bool isServerMode() const { return serwerMode; }

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_btn_start_connect_clicked();

    void on_btn_stop_disconnect_clicked();
public slots:
    void sendModel(const ARXModel& model);
    void receiveModel(const QByteArray& data);

signals:
    void connectionStarted(bool isServerMode);  // true = server, false = client
    void connectionStopped();
    void clientStarted();
    void modelReceived(ARXModel model);

private:
    Ui::oknosiec *ui;
    bool serwerMode = true;
    Network *network = nullptr;
    void closeEvent(QCloseEvent* event) override;
};

#endif // oknosiec_H
