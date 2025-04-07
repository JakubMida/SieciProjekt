#pragma once

#include "arx.h"
#include "regulator.h"

class UkladRegulacji 
{
private:
    RegulatorPID regulator;
    ARXModel model;
    double poprzednie_wyjscie = 0.0;
    double sygnal = 0.0;
    double uchyb = 0.0;

public:
    UkladRegulacji(RegulatorPID& reg, ARXModel& mod);

    double symulujKrok(double wartosc);

    RegulatorPID& getRegulator();
    ARXModel& getModel();
    double getPoprzednieWyjscie();
    double getUchyb();
    double getSygnal();
    void reset();
};
