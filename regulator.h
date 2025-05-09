#pragma once
#include <QDebug>

enum class Filtr
{
    ON,
    OFF
};

enum class TrybCalkowania
{
    STALA_PRZED_SUMA,
    STALA_POD_SUMA
};

class RegulatorPID {
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

public:

    RegulatorPID();
    RegulatorPID(double k);
    RegulatorPID(double k, double Ti);
    RegulatorPID(double k, double Ti, double Td);
    void setK(double k);
    void setTi(double Ti);
    void setTd(double Td);
    void setGranicaDolna(double granicaDolna);
    void setGranicaGorna(double granicaGorna);
    void setFiltr(Filtr f);
    void setTryb(TrybCalkowania t);
    double getK();
    double getTi();
    double getTd();
    double getUip();
    double getUii();
    double getUid();
    double getGranicaDolna();
    double getGranicaGorna();
    double symuluj(double uchyb);
    double getPoprzedniUchyb();
    void reset();
};
