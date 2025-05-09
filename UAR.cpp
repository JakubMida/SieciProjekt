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
        uchyb = wejscie - poprzednie_wyjscie;

        sygnal = regulator.symuluj(uchyb);

        poprzednie_wyjscie = model.symulacja(sygnal);

        emit wyslacWartoscSterowania(sygnal);

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
        emit wyslacStanArx(utworzStanArx());
    }
}
arxStan UkladRegulacji::utworzStanArx() {
    arxStan stan;
    stan.A = model.getVectorA();
    stan.B = model.getVectorB();
    stan.opoznienie = model.getOpoznienie();
    stan.zaklocenie = model.getZaklocenie();
    //stan.wejscia = model.getWejscia();
    //stan.wyjscia = model.getWyjscia();
    // Note: not copying generator and rozklad, since they can't be copied directly

    return stan;
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

void UkladRegulacji::onSiecArxStan(arxStan stan) {
    qDebug() << "[UAR] onSiecArxStan";

    // Update internal model with received ARX state
    model.setVectorA(stan.A);
    model.setVectorB(stan.B);
    model.setOpoznienie(stan.opoznienie);
    model.setZaklocenie(stan.zaklocenie);
    /*
    model.wejscia = stan.wejscia;
    model.wyjscia = stan.wyjscia;
    */
}
