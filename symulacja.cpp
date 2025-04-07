#include "symulacja.h"

symulacja::symulacja(RegulatorPID& regulator, ARXModel& model): krokCzasowy(0.05), czasSymulacji(0.0), uruchomiona(false), wartosc(0.0)
{
    zadajnik = new Zadajnik();
    uar = new UkladRegulacji(regulator, model);
}

void symulacja::start()
{
    this->uruchomiona = true;
}

void symulacja::stop()
{
    this->uruchomiona = false;
}

void symulacja::reset()
{
    this->czasSymulacji = 0.0;
    this->wartosc = 0.0;
    this->getUAR()->getRegulator().reset();
    this->getUAR()->getModel().reset();
    this->getUAR()->reset();
}

void symulacja::wykonajKrok()
{
    if(!uruchomiona) return;
    czasSymulacji += krokCzasowy;
    wartosc = zadajnik->generujSygnal(czasSymulacji, zadajnik->getTyp());
    sygnal = uar->symulujKrok(wartosc);
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
}

double symulacja::getKrokCzasowy()
{
    return this->krokCzasowy;
}

bool symulacja::getCzyUruchomiona()
{
    return this->uruchomiona;
}
