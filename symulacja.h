#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "zadajnik.h"
#include "UAR.h"
#include <QDebug>

class symulacja
{
    double krokCzasowy;
    double czasSymulacji;
    Zadajnik* zadajnik;
    bool uruchomiona;
    double wartosc;
    double sygnal;
    double uchyb;
    UkladRegulacji* uar;
public:
    symulacja(RegulatorPID& regulator, ARXModel& model);
    void start();
    void stop();
    void reset();
    void wykonajKrok();
    double getWartoscZadana();
    double getCzas();
    double getSygnal();
    void setKrokCzasowy(int interwal);
    double getKrokCzasowy();
    bool getCzyUruchomiona();
    Zadajnik* getZadajnik();
    UkladRegulacji* getUAR();
};

#endif // SYMULACJA_H
