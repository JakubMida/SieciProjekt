#include "UAR.h"

UkladRegulacji::UkladRegulacji(RegulatorPID& reg, ARXModel& mod)
    : regulator(reg), model(mod), poprzednie_wyjscie(0.0) {}

double UkladRegulacji::symulujKrok() {
   
    uchyb = wejscie - poprzednie_wyjscie;

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

void UkladRegulacji::setWejscie(double wartosc){
    wejscie = wartosc;
}

void UkladRegulacji::onSiecRegulowania(double wartosc){
    qDebug() << "onSiecRegulowania";
    if(trybSieciowy != TrybSieciowy::Serwer) return;
    ostatniaWartoscSieciowa = wartosc;
    czyJestWartoscSieciowa = true;
    symulujKrokSieciowy();
}
void UkladRegulacji::onSiecSterowania(double wartosc){
    qDebug() << "onSiecSterowania";
    ostatniaWartoscSieciowa = wartosc;
    czyJestWartoscSieciowa = true;
}

void UkladRegulacji::symulujKrokSieciowy() {
    qDebug() << "[UAR] Krok sieciowy, tryb = " << (int)this->trybSieciowy;

    if (this->trybSieciowy == TrybSieciowy::Serwer) {
        qDebug() << "[UAR] Krok sieciowy serwer";
        if (!czyJestWartoscSieciowa) {
            qDebug() << "[UAR] No network value received yet.";
            label->setStyleSheet("background-color: red; border-radius: 10px;");
            return;
        }
        label->setStyleSheet("background-color: green; border-radius: 10px;");
        double u = ostatniaWartoscSieciowa;
        czyJestWartoscSieciowa = false;

        // Simulate the system and send the regulated value
        double y = model.symulacja(u);
        qDebug() << "[UAR] Simulated regulated value (y):" << y;
        emit wyslacWartoscRegulowania(y);
        emit noweDaneSymulacji();

    } else if (this->trybSieciowy == TrybSieciowy::Klient) {
        qDebug() << "[UAR] Krok sieciowy klient";
        uchyb = wejscie - poprzednie_wyjscie;

        // Calculate the control signal and send it
        sygnal = regulator.symuluj(uchyb);
        qDebug() << "[UAR] Calculated control signal (u):" << sygnal;
        poprzednie_wyjscie = model.symulacja(sygnal);
        emit wyslacWartoscSterowania(sygnal);

        double y = czyJestWartoscSieciowa ? ostatniaWartoscSieciowa : poprzednie_wyjscie;
        czyJestWartoscSieciowa = false;
        poprzednie_wyjscie = y;
        emit noweDaneSymulacji();
    }
}

void UkladRegulacji::setTrybSieciowy(TrybSieciowy trybSieciowy){
    this->trybSieciowy = trybSieciowy;
}

TrybSieciowy UkladRegulacji::getTrybSieciowy(){
    return this->trybSieciowy;
}

void UkladRegulacji::setLabel(QLabel* lbl) {
    label = lbl;
}
