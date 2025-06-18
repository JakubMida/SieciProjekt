#include "symulacja.h"

symulacja::symulacja(RegulatorPID& regulator, ARXModel& model): krokCzasowy(0.05), czasSymulacji(0.0), uruchomiona(false), wartosc(0.0)
{
    zadajnik = new Zadajnik();
    uar = new UkladRegulacji(regulator, model);
}

void symulacja::start()
{
    this->uruchomiona = true;
    if(int(this->trybSieciowy) == 2) emit wyslacStartSygnal();
}

void symulacja::stop()
{
    this->uruchomiona = false;
    if(int(this->trybSieciowy) == 2) emit wyslacStopSygnal();
}

void symulacja::reset()
{
    this->czasSymulacji = 0.0;
    this->wartosc = 0.0;
    this->getUAR()->getRegulator().reset();
    this->getUAR()->getModel().reset();
    this->getUAR()->reset();
    if(int(this->trybSieciowy) == 2) emit wyslacResetSygnal();
}

void symulacja::wykonajKrok()
{
    if(!uruchomiona) return;
    czasSymulacji += krokCzasowy;

    uar->setCzasSieciowy(czasSymulacji);
    wartosc = zadajnik->generujSygnal(czasSymulacji, zadajnik->getTyp());
    uar->setWejscie(wartosc);
    if((int)trybSieciowy == 0){
        sygnal = uar->symulujKrok();
    }
    else
    {
        uar->setTrybSieciowy(this->trybSieciowy);
        uar->symulujKrokSieciowy();
    }
}

double symulacja::getWartoscZadana()
{
    return wartosc;
}

double symulacja::getCzas()
{
    return czasSymulacji;
}

Zadajnik* symulacja::getZadajnik()
{
    return zadajnik;
}

UkladRegulacji* symulacja::getUAR()
{
    return uar;
}

double symulacja::getSygnal()
{
    return sygnal;
}

void symulacja::setKrokCzasowy(int interwal)
{
    this->krokCzasowy = interwal / 1000.0;
    if(int(trybSieciowy) == 2) {
        uar->setSerwerTimerInterwal(interwal);
        emit wyslacInterwalNaSerwer(interwal);
    }
}

double symulacja::getKrokCzasowy()
{
    return this->krokCzasowy;
}

bool symulacja::getCzyUruchomiona()
{
    return this->uruchomiona;
}

void symulacja::onSiecZmierzona(double wartosc){
    qDebug() << "Not implemented";
}
void symulacja::onSiecSterowania(double wartosc){
    qDebug() << "Not implemented";
}

void symulacja::setTrybSieciowy(TrybSieciowy trybSieciowy){
    this->trybSieciowy = trybSieciowy;
    this->getUAR()->setTrybSieciowy(trybSieciowy);
}

TrybSieciowy symulacja::getTrybSieciowy(){
    return this->trybSieciowy;
}


void symulacja::onSiecSymulacjaStan(symulacjaStan stan) {
    qDebug() << "[UAR] onSiecSymulacjaStan";

    // Update internal simulation state
    //zadajnik
    zadajnik->setAmplituda(stan.amplituda);
    zadajnik->setOkres(stan.okres);
    zadajnik->setWypelnienie(stan.wypelnienie);
    zadajnik->setSkladowa(stan.skladowaStala);
    zadajnik->setCzasAktywacji(stan.czasAktywacji);
    zadajnik->setTyp(stan.typ);

    uar->getRegulator().setK(stan.k);
    uar->getRegulator().setTi(stan.Ti);
    uar->getRegulator().setTd(stan.Td);
    /*
    uar->getRegulator().set = stan.Uip;
    this->regulator.Uii = stan.Uii;
    this->regulator.Uid = stan.Uid;
    uar->getRegulator()->set
    this->regulator.suma_uchybow = stan.suma_uchybow;
    this->regulator.poprzedni_uchyb = stan.poprzedni_uchyb;
    */
    uar->getRegulator().setGranicaDolna(stan.granicaDolna);
    uar->getRegulator().setGranicaGorna(stan.granicaGorna);
    uar->getRegulator().setFiltr(stan.filtr);
    uar->getRegulator().setTryb(stan.tryb);

    //this->poprzednie_wyjscie = stan.poprzednie_wyjscie;
    this->sygnal = stan.sygnal;
    this->uchyb = stan.uchyb;

    this->krokCzasowy = stan.krokCzasowy;
    this->czasSymulacji = stan.czasSymulacji;
    //this->czySymulacjaUruchomiona = stan.uruchomiona;
    this->wartosc = stan.wartosc;
}


symulacjaStan symulacja::utworzStanSymulacji() {
    symulacjaStan stan;

    // Zadajnik
    stan.amplituda = zadajnik->getAmplituda();
    stan.okres = zadajnik->getOkres();
    stan.wypelnienie = zadajnik->getWypelnienie();
    stan.skladowaStala = zadajnik->getSkladowaStala();
    stan.czasAktywacji = zadajnik->getCzasAktywacji();
    stan.typ = zadajnik->getTyp();

    // Regulator PID
    auto& reg = uar->getRegulator();
    stan.k = reg.getK();
    stan.Ti = reg.getTi();
    stan.Td = reg.getTd();
    stan.Uip = reg.getUip();
    stan.Uii = reg.getUii();
    stan.Uid = reg.getUid();
    //stan.suma_uchybow = reg.getSumaUchybow();
    stan.poprzedni_uchyb = reg.getPoprzedniUchyb();
    stan.granicaDolna = reg.getGranicaDolna();
    stan.granicaGorna = reg.getGranicaGorna();
    //stan.filtr = reg.getFiltr();
    //stan.tryb = reg.getTryb();

    // UAR (system)
    stan.poprzednie_wyjscie = uar->getPoprzednieWyjscie();
    stan.sygnal = uar->getSygnal();
    stan.uchyb = uar->getUchyb();

    // Symulacja
    stan.krokCzasowy = krokCzasowy;
    stan.czasSymulacji = czasSymulacji;
    stan.uruchomiona = uruchomiona;
    stan.wartosc = wartosc;

    return stan;
}

void symulacja::onResetSygnal(){
    emit resetWykresy();
    reset();
    //this->uar->setSerwerTimerInterwal(this->uar->getSerwerTimerInterwal()/3); // ???
    qDebug() << "[symulacja] onReset";
    emit resetWykresy();
}

void symulacja::onWykonajKrokLokalnieNaSerwerze(){
    qDebug() << "[symulacja] onWykonajKrokLokalnieNaSerwerze krokCzasowy" << krokCzasowy;
    czasSymulacji += krokCzasowy;
    //uar->setCzasSieciowy(czasSymulacji);
    wartosc = zadajnik->generujSygnal(czasSymulacji, zadajnik->getTyp());
    uar->setWejscie(wartosc);
}

void symulacja::onWyslacKrokSieciowyNaSymulator(int interwal){
    qDebug() << "onWyslacKrokSieciowyNaSymulator interwal " << interwal;
    setKrokCzasowy(interwal);
}

void symulacja::onWyslacInterwalNaSerwer(int interwal){
    if(int(this->trybSieciowy) == 1){
        qDebug() << "[symulacja] onWyslacInterwalNaSerwer interwal " << interwal;
        setKrokCzasowy(interwal);
    }
}
