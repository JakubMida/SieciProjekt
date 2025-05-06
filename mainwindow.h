#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "symulacja.h"
#include <QTimer>
#include <arx.h>
#include <network.h>
#include <oknosiec.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setControlsEnabled(bool mode);

private slots:
    void on_startButton_clicked();
    void aktualizujWykres();
    void on_stopButton_clicked();

    void on_resetButton_clicked();

    void on_valueSpinBox_editingFinished();

    void on_okresSpinBox_editingFinished();

    void on_wypelnienieSpinBox_editingFinished();

    void on_comboBox_activated(int index);

    void on_GornaGranica_editingFinished();

    void on_DolnaGranica_editingFinished();

    void on_AntyWindUP_checkStateChanged(const Qt::CheckState &arg1);

    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_kSpinBox_editingFinished();

    void on_tiSpinBox_editingFinished();

    void on_tdSpinBox_editingFinished();

    void on_interwalSpinBox_editingFinished();

    void on_btnModelARx_clicked();

    void on_czasAktywacjiSpinBox_editingFinished();

    void on_skladowaStalaSpinBox_editingFinished();

    void on_AntyWindUP_stateChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_cbxCzarnyMotyw_stateChanged(int arg1);

    void on_btn_network_clicked();

private:
    Ui::MainWindow *ui;
    symulacja *sym;
    QTimer *timer;
    void setupPlots();
    oknosiec* oknoSiec = nullptr;
};
#endif // MAINWINDOW_H
