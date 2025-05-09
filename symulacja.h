#ifndef SYMULACJA_H
#define SYMULACJA_H
#include "zadajnik.h"
#include "UAR.h"
#include <QDebug>
#include "qobject.h"
#include "trybSieciowy.h"

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

    TrybSieciowy trybSieciowy = TrybSieciowy::Offline;

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

    TrybSieciowy getTrybSieciowy();
    void setTrybSieciowy(TrybSieciowy trybSieciowy);

    symulacjaStan utworzStanSymulacji();

public slots:
    void onSiecZmierzona(double wartosc);
    void onSiecSterowania(double wartosc);
    void wykonajKrok();

    void onSiecSymulacjaStan(symulacjaStan symStan);
signals:
    void noweDaneSymulacji();
    void wyslacWartoscZmierzona(double wartosc);
    void wyslacWartoscSterowania(double wartosc);

    void wyslacStanSymulacji(symulacjaStan symStan);
};

#endif // SYMULACJA_H
