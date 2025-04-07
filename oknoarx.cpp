#include "oknoarx.h"
#include "ui_oknoarx.h"

OknoARX::OknoARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OknoARX)
{
    ui->setupUi(this);
    connect(ui->btnOK,&QPushButton::clicked,this,&OknoARX::accept);
    connect(ui->btnAnuluj,&QPushButton::clicked,this,&OknoARX::reject);
}

OknoARX::~OknoARX()
{
    delete ui;
}

int OknoARX::getOpoznienie()
{
    return ui->delaySpinBox_2->value();
}

double OknoARX::getVectorA()
{

   return ui->vectoraSpinBox_2->value();
}

double OknoARX::getVectorAA()
{

   return ui->vectoraaSpinBox_2->value();
}

double OknoARX::getVectorAAA()
{

   return ui->vectoraaa_2->value();
}

double OknoARX::getVectorB()
{
   return ui->vectorbSpinBox_2->value();
}
double OknoARX::getVectorBB()
{
   return ui->vectorbbSpinBox_2->value();
}
double OknoARX::getVectorBBB()
{
   return ui->vectorbbb_2->value();
}

double OknoARX::getZaklocenie()
{
    return ui->zaklocenieSpinBox_2->value();
}

void OknoARX::setOpoznienie(int value)
{
    ui->delaySpinBox_2->setValue(value);

}

void OknoARX::setZaklocenie(double value)
{
    ui->zaklocenieSpinBox_2->setValue(value);
}

void OknoARX::setVectorA(double value)
{
    ui->vectoraSpinBox_2->setValue(value);
}

void OknoARX::setVectorAA(double value)
{
    ui->vectoraaSpinBox_2->setValue(value);
}
void OknoARX::setVectorAAA(double value)
{
    ui->vectoraaa_2->setValue(value);
}
void OknoARX::setVectorB(double value)
{
    ui->vectorbSpinBox_2->setValue(value);
}
void OknoARX::setVectorBB(double value)
{
    ui->vectorbbSpinBox_2->setValue(value);
}
void OknoARX::setVectorBBB(double value)
{
    ui->vectorbbb_2->setValue(value);
}
