#include "UAR.h"
#include <QTimer>

UkladRegulacji::UkladRegulacji(RegulatorPID& reg, ARXModel& mod)
    : regulator(reg), model(mod), poprzednie_wyjscie(0.0), serverSideTimer(new QTimer(this)) {
    connect(serverSideTimer, &QTimer::timeout, this, &UkladRegulacji::symulujKrokObustronnie);
}

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
    ostatniaWartoscSieciowa = y;
    czyJestWartoscSieciowa = true;
    poprzednie_wyjscie = ostatniaWartoscSieciowa; // !!!!!
    qDebug() << "[UAR] onSiecRegulowania, ostatniaWartoscSieciowa=" << ostatniaWartoscSieciowa;
}
void UkladRegulacji::onSiecSterowania(double u, double czas, double wartoscZadana){
    qDebug() << "[UAR Server] wartoscSterowania otrymana:" << u;
    if (trybSieciowy != TrybSieciowy::Serwer) return;

    ostatniaWartoscSieciowa = u;
    czasSieciowy = czas;
    wartoscZadanaSieciowa = wartoscZadana;
    czyJestWartoscSieciowa = true;
    symulujKrokSieciowy(); // test !!
}

void UkladRegulacji::onSiecTrybTaktowania(int interwal){
    qDebug() << "[UAR Server] interwal otrzymany:" << interwal;
    setSerwerTimerInterwal(interwal);
    if(interwal <=0){
        setTrybTaktowania(false);
    }
    else{
        setTrybTaktowania(true);
        serverSideTimer->setInterval(interwal * 1000.0);
    }
}

void UkladRegulacji::onStartSygnal(){
    //if(getTrybTaktowania()) serverSideTimer->start(getSerwerTimerInterwal()); // !!!!!
    if(getTrybTaktowania()) serverSideTimer->start(0);
    qDebug() << "[UAR] onStartSygnal " << getTrybTaktowania() << "interwal real" << serverSideTimer->interval() << "interwal get" << getSerwerTimerInterwal();

}

void UkladRegulacji::onStopSygnal(){
    if(getTrybTaktowania()) serverSideTimer->stop();
    qDebug() << "[UAR] onStopSygnal" << getTrybTaktowania();
}

void UkladRegulacji::symulujKrokSieciowy() {
    if(int(this->trybSieciowy) == 2){
        uchyb = wejscie - poprzednie_wyjscie;

        sygnal = regulator.symuluj(uchyb);

        poprzednie_wyjscie = model.symulacja(sygnal);

        emit wyslacWartoscSterowania(sygnal, czasSieciowy, wejscie);

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
        //emit noweDaneSymulacji();
    }
    if(int(this->trybSieciowy) == 1){
        qDebug() << "[UAR Serwer] tryb taktowania = " << getTrybTaktowania();
        if(!getTrybTaktowania()){
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
            qDebug() << "[UAR Serwer] wysyłam wartosc regulowania" << y << "w czasie " << czasSieciowy << "opoznienie arx = " << model.getOpoznienie();

            // треба тут вислати дані на викреси
            emit aktualizujWykresSerwer(czasSieciowy, wartoscZadanaSieciowa, u, y);
            emit wyslacStanArx(utworzStanArx());
        }
    }
}

void UkladRegulacji::symulujKrokObustronnie(){
    qDebug() << "[UAR Serwer] symulujKrokObustronnie";
    qDebug() << "[UAR Serwer Obustronnie] czyJestWartoscSieciowa=" << czyJestWartoscSieciowa;
    if(!czyJestWartoscSieciowa){
        //label->setStyleSheet("background-color: red; border-radius: 10px;");
        return;
    }
    label->setStyleSheet("background-color: green; border-radius: 10px;");
    double u = ostatniaWartoscSieciowa;
    czyJestWartoscSieciowa = false;
    double y = model.symulacja(u);
    emit wyslacWartoscRegulowania(y);
    emit aktualizujWykresSerwer(czasSieciowy, wartoscZadanaSieciowa, u, y);
    emit wyslacStanArx(utworzStanArx());

}
arxStan UkladRegulacji::utworzStanArx() {
    arxStan stan;
    stan.A = model.getVectorA();
    stan.B = model.getVectorB();
    stan.opoznienie = model.getOpoznienie();
    stan.zaklocenie = model.getZaklocenie();
    stan.wejscia = model.getWejscia();
    stan.wyjscia = model.getWyjscia();
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
    if(int(getTrybSieciowy()) == 2)
    {
        qDebug() << "[UAR] onSiecArxStan client";

        model.setVectorA(stan.A);
        model.setVectorB(stan.B);
        model.setOpoznienie(stan.opoznienie);
        model.setZaklocenie(stan.zaklocenie);
        model.setWejscia(stan.wejscia);
        model.setWyjscia(stan.wyjscia);
    }
}


void UkladRegulacji::setCzasSieciowy(double czas) {
    this->czasSieciowy = czas;
}

double UkladRegulacji::getCzasSieciowy(){
    return this->czasSieciowy;
}

void UkladRegulacji::setWartoscZadanaSieciowa(double wartoscZadanaSieciowa) {
    this->wartoscZadanaSieciowa = wartoscZadanaSieciowa;
}

double UkladRegulacji::getWartoscZadanaSieciowa() {
    return this->wartoscZadanaSieciowa;
}

bool UkladRegulacji::getTrybTaktowania(){
    return this->trybTaktowania;
}
void UkladRegulacji::setTrybTaktowania(bool tryb){
    this->trybTaktowania = tryb;
}

int UkladRegulacji::getSerwerTimerInterwal(){
    return this->serwerTimerInterwal;
}

void UkladRegulacji::setSerwerTimerInterwal(int interwal){
    this->serwerTimerInterwal = interwal;
    emit wyslacTrybTaktowania(interwal);
    qDebug() << "[UAR] wyslacTrybTaktowania" << interwal;
}
