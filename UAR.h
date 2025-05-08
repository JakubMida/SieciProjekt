#pragma once

#include "arx.h"
#include "regulator.h"
#include "qobject.h"

class UkladRegulacji : public QObject
{
    Q_OBJECT

private:
    double wejscie;

    RegulatorPID regulator;
    ARXModel model;
    double poprzednie_wyjscie = 0.0;
    double sygnal = 0.0;
    double uchyb = 0.0;

public:
    UkladRegulacji(RegulatorPID& reg, ARXModel& mod);
    void setWejscie(double wartosc);

    double symulujKrok();

    RegulatorPID& getRegulator();
    ARXModel& getModel();
    double getPoprzednieWyjscie();
    double getUchyb();
    double getSygnal();
    void reset();

public slots:
    void onSiecZmierzona(double wartosc);
    void onSiecSterowania(double wartosc);
    void symulujKrokSieciowy();

signals:
    void noweDaneSymulacji();
    void wyslacWartoscZmierzona(double wartosc);
    void wyslacWartoscSterowania(double wartosc);
};
