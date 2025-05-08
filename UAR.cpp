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

void UkladRegulacji::symulujKrokSieciowy(){
    qDebug() << "not implemented";
    if(this->trybSieciowy == TrybSieciowy::Serwer){
        qDebug() << "[UAR Siec] czy ma nowa wartosc z sieci = " << czyJestWartoscSieciowa;
        if(!czyJestWartoscSieciowa){
            label->setStyleSheet("background-color: red; border-radius: 10px;");
            return;
        }
        label->setStyleSheet("background-color: green; border-radius: 10px;");
        double u = ostatniaWartoscSieciowa;
        czyJestWartoscSieciowa = false;
        double y = model.symulacja(u);
        emit wyslacWartoscRegulowania(y);
        emit noweDaneSymulacji();

    }
    else if(this->trybSieciowy == TrybSieciowy::Klient){
        uchyb = wejscie - poprzednie_wyjscie;

        sygnal = regulator.symuluj(uchyb);

        poprzednie_wyjscie = model.symulacja(sygnal);

        emit wyslacWartoscSterowania(sygnal);

        double y=0;
        if(czyJestWartoscSieciowa){
            label->setStyleSheet("background-color: green; border-radius: 10px;");
            y = ostatniaWartoscSieciowa;
            czyJestWartoscSieciowa = false;
        }
        else{
            label->setStyleSheet("background-color: red; border-radius: 10px;");
            y = poprzednie_wyjscie;  // timeout / brak pakietu
        }
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
