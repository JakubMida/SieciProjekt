#ifndef SYMULACJASTAN_H
#define SYMULACJASTAN_H
#include "zadajnik.h"
#include "regulator.h"

struct symulacjaStan{
    //zadajnik
    double amplituda = 0;
    double okres = 0;
    double wypelnienie = 0;
    double skladowaStala;
    double czasAktywacji;
    TypSygnalu typ;

    //regulator pid
    double k;
    double Ti;
    double Td;
    double Uip = 0.0;
    double Uii = 0.0;
    double Uid = 0.0;
    double suma_uchybow;
    double poprzedni_uchyb;
    double granicaDolna = 0.0;
    double granicaGorna = 10.0;
    Filtr filtr = Filtr::OFF;
    TrybCalkowania tryb = TrybCalkowania::STALA_PRZED_SUMA;

    //UAR
    double poprzednie_wyjscie = 0.0;
    double sygnal = 0.0;
    double uchyb = 0.0;

    //symulacja
    double krokCzasowy;
    double czasSymulacji;
    bool uruchomiona;
    double wartosc;
};


#endif // SYMULACJASTAN_H
