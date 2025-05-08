#ifndef SYMULACJA_H
#define SYMULACJA_H
#include "zadajnik.h"
#include "UAR.h"
#include <QDebug>
#include "qobject.h"

class symulacja : public QObject
{
    Q_OBJECT

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

    double getWartoscZadana();
    double getCzas();
    double getSygnal();
    void setKrokCzasowy(int interwal);
    double getKrokCzasowy();
    bool getCzyUruchomiona();
    Zadajnik* getZadajnik();
    UkladRegulacji* getUAR();

public slots:
    void onSiecZmierzona(double wartosc);
    void onSiecSterowania(double wartosc);
    void wykonajKrok();
signals:
    void noweDaneSymulacji();
    void wyslacWartoscZmierzona(double wartosc);
    void wyslacWartoscSterowania(double wartosc);
};

#endif // SYMULACJA_H
