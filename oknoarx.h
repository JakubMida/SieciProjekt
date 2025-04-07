#ifndef OKNOARX_H
#define OKNOARX_H

#include <QDialog>

namespace Ui {
class OknoARX;
}

class OknoARX : public QDialog
{
    Q_OBJECT

public:
    explicit OknoARX(QWidget *parent = nullptr);
    ~OknoARX();
    int getOpoznienie();
    double getVectorA();
    double getVectorAA();
    double getVectorAAA();
    double getVectorB();
    double getVectorBB();
    double getVectorBBB();
    double getZaklocenie();
    void setOpoznienie(int value);
    void setZaklocenie(double value);
    void setVectorA(double value);
    void setVectorAA(double value);
    void setVectorAAA(double value);
    void setVectorB(double value);
    void setVectorBB(double value);
    void setVectorBBB(double value);

private:
    Ui::OknoARX *ui;

};

#endif // OKNOARX_H
