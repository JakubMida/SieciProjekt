#ifndef oknosiec_H
#define oknosiec_H

#include <QDialog>
#include <QCloseEvent>
#include "network.h"

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

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_btn_start_connect_clicked();

    void on_btn_stop_disconnect_clicked();

private:
    Ui::oknosiec *ui;
    bool serwerMode = true;
    Network *network = nullptr;
    void closeEvent(QCloseEvent* event) override;
};

#endif // oknosiec_H
