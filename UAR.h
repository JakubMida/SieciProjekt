#pragma once
#include "arx.h"
#include "regulator.h"
#include "qobject.h"
#include "trybSieciowy.h"
#include <qlabel.h>
#include "network.h"


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

    TrybSieciowy trybSieciowy = TrybSieciowy::Offline;
    double ostatniaWartoscSieciowa = 0.0;
    bool czyJestWartoscSieciowa = true;

    QLabel* label=nullptr;
    bool waitingForSync = false;
    Network* network = nullptr;
    int expectedSampleNumber = 0;
    int sampleNumber = 0;

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

    TrybSieciowy getTrybSieciowy();
    void setTrybSieciowy(TrybSieciowy trybSieciowy);

    void uruchomPoPolaczeniu();

    void setLabel(QLabel* lbl);
    void setNetwork(Network* net);

public slots:
    void onSiecRegulowania(double wartosc);
    void onSiecSterowania(double wartosc);
    void symulujKrokSieciowy();
    void onSyncCommand(NetworkCommand cmd, int sampleNumber);

signals:
    void noweDaneSymulacji();
    void wyslacWartoscRegulowania(double wartosc);
    void wyslacWartoscSterowania(double wartosc);
};
