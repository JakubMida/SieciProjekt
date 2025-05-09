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

void UkladRegulacji::onSiecRegulowania(double y){
    qDebug() << "[UAR] onSiecRegulowania";
    ostatniaWartoscSieciowa = y;
    czyJestWartoscSieciowa = true;
}
void UkladRegulacji::onSiecSterowania(double u){
    qDebug() << "[UAR Server] wartoscSterowania otrymana:" << u;
    if (trybSieciowy != TrybSieciowy::Serwer) return;

    ostatniaWartoscSieciowa = u;
    czyJestWartoscSieciowa = true;
    symulujKrokSieciowy(); // test
}

void UkladRegulacji::symulujKrokSieciowy() {
    if(int(this->trybSieciowy) == 2){
        qDebug() << "[UAR Klient]";
        uchyb = wejscie - poprzednie_wyjscie;

        sygnal = regulator.symuluj(uchyb);

        poprzednie_wyjscie = model.symulacja(sygnal);

        emit wyslacWartoscSterowania(sygnal);
        network->sendCommand(NetworkCommand::Step, expectedSampleNumber);

        double y = 0;
        if(czyJestWartoscSieciowa){
            label->setStyleSheet("background-color: green; border-radius: 10px;");
            y = ostatniaWartoscSieciowa;
            czyJestWartoscSieciowa= false;
        }
        else{
            label->setStyleSheet("background-color: red; border-radius: 10px;");
            y = poprzednie_wyjscie;
        }
        poprzednie_wyjscie=y;
        emit noweDaneSymulacji();
    }
    if(int(this->trybSieciowy) == 1){
        qDebug() << "[UAR Serwer] czyJestWartoscSieciowa="
                 << czyJestWartoscSieciowa;
        if(!czyJestWartoscSieciowa){
            label->setStyleSheet("background-color: red; border-radius: 10px;");
            return;
        }
        label->setStyleSheet("background-color: green; border-radius: 10px;");
        double u = ostatniaWartoscSieciowa;
        czyJestWartoscSieciowa = false;
        double y = model.symulacja(u);
        emit wyslacWartoscRegulowania(y);
        network->sendCommand(NetworkCommand::Sync, sampleNumber);
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

void UkladRegulacji::onSyncCommand(NetworkCommand cmd, int sampleNumber)
{
    switch(cmd) {
    case NetworkCommand::Start:
        // Rozpocznij symulację
        break;
    case NetworkCommand::Stop:
        // Zatrzymaj symulację
        break;
    case NetworkCommand::Step:
        if (trybSieciowy == TrybSieciowy::Serwer) {
            if (sampleNumber == expectedSampleNumber) {
                symulujKrokSieciowy();
                expectedSampleNumber++;
            } else {
                // Błąd synchronizacji
                qDebug() << "Błąd synchronizacji! Oczekiwano:" << expectedSampleNumber
                         << "Otrzymano:" << sampleNumber;
            }
        }
        break;
    case NetworkCommand::Sync:
        if (trybSieciowy == TrybSieciowy::Klient) {
            if (sampleNumber == expectedSampleNumber) {
                symulujKrokSieciowy();
                expectedSampleNumber++;
            } else {
                // Błąd synchronizacji
                qDebug() << "Błąd synchronizacji! Oczekiwano:" << expectedSampleNumber
                         << "Otrzymano:" << sampleNumber;
            }
        }
        break;
    }
}

void UkladRegulacji::setNetwork(Network* net) {
    network = net;
}
