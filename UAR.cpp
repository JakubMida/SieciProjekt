#include "UAR.h"

UkladRegulacji::UkladRegulacji(RegulatorPID& reg, ARXModel& mod)
    : regulator(reg), model(mod), poprzednie_wyjscie(0.0) {}

double UkladRegulacji::symulujKrok(double wartosc) {
   
    uchyb = wartosc - poprzednie_wyjscie;

    sygnal = regulator.symuluj(uchyb);

    poprzednie_wyjscie = model.symulacja(sygnal);

    return sygnal;
}

RegulatorPID& UkladRegulacji::getRegulator(){
    return regulator;
}

ARXModel& UkladRegulacji::getModel(){
    return model;
}

double UkladRegulacji::getPoprzednieWyjscie()
{
    return poprzednie_wyjscie;
}

double UkladRegulacji::getUchyb()
{
    return uchyb;
}

double UkladRegulacji::getSygnal()
{
    return sygnal;
}
void UkladRegulacji::reset()
{
    poprzednie_wyjscie=0.0;
    sygnal = 0.0;
    uchyb = 0.0;
}
