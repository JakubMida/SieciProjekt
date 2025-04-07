#include "regulator.h"

RegulatorPID::RegulatorPID(): k(0.5), Ti(5.0), Td(0.2), suma_uchybow(0.0), poprzedni_uchyb(0.0){}

RegulatorPID::RegulatorPID(double k) :Ti(0.0), Td(0.0), suma_uchybow(0.0), poprzedni_uchyb(0.0) 
{
    setK(k);
}

RegulatorPID::RegulatorPID(double k, double Ti) : Td(0), suma_uchybow(0.0), poprzedni_uchyb(0.0) 
{
    setK(k);
    setTi(Ti);
}

RegulatorPID::RegulatorPID(double k, double Ti, double Td) : suma_uchybow(0.0), poprzedni_uchyb(0.0) 
{
    setK(k);
    setTi(Ti);
    setTd(Td);
}

double RegulatorPID::symuluj(double uchyb) 
{
    Uip = k * uchyb;

    if (Ti > 0.0)
    {
        if(tryb == TrybCalkowania::STALA_PRZED_SUMA)
        {
            suma_uchybow += uchyb;
            Uii = (suma_uchybow / Ti);
        }
        else if(tryb == TrybCalkowania::STALA_POD_SUMA)
        {
            Uii += (uchyb / Ti);
        }
    }
    if (Td > 0.0)
    {
        Uid = Td * (uchyb - poprzedni_uchyb);
    }
    poprzedni_uchyb = uchyb;

    double wartoscRegulowana = Uip + Uii + Uid;

    if (!static_cast<int>(filtr))
    {
        if (wartoscRegulowana < granicaDolna)
        {
            wartoscRegulowana = granicaDolna;
            suma_uchybow -= uchyb;
        }
        if (wartoscRegulowana > granicaGorna)
        {
            wartoscRegulowana = granicaGorna;
            suma_uchybow -= uchyb;
        }
    }

    return wartoscRegulowana;
}

void RegulatorPID::reset() 
{
    suma_uchybow = 0.0;
    poprzedni_uchyb = 0.0;
    Uip = 0.0;
    Uii = 0.0;
    Uid = 0.0;
}

double RegulatorPID::getPoprzedniUchyb()
{
    return this->poprzedni_uchyb;
}

void RegulatorPID::setK(double k)
{
    k > 0.0 ? this->k = k : this->Ti = 0.0;
}

void RegulatorPID::setTi(double Ti)
{
    Ti > 0.0 ? this->Ti = Ti : this->Ti = 0.0;
}

void RegulatorPID::setTd(double Td)
{
    Td > 0.0 ? this->Td = Td : this->Td = 0.0;
}

double RegulatorPID::getK()
{
    return this->k;
}

double RegulatorPID::getTi()
{
    return this->Ti;
}

double RegulatorPID::getTd()
{
    return this->Td;
}

void RegulatorPID::setGranicaDolna(double granicaDolna)
{
    this->granicaDolna = granicaDolna;
}

double RegulatorPID::getGranicaDolna()
{
    return this->granicaDolna;
}

void RegulatorPID::setGranicaGorna(double granicaGorna)
{
    this->granicaGorna = granicaGorna;
}

double RegulatorPID::getGranicaGorna()
{
    return this->granicaGorna;
}

void RegulatorPID::setFiltr(Filtr f)
{
    this->filtr = f;
}

double RegulatorPID::getUip()
{
    return Uip;
}

double RegulatorPID::getUii()
{
    return Uii;
}

double RegulatorPID::getUid()
{
    return Uid;
}

void RegulatorPID::setTryb(TrybCalkowania t)
{
    this->tryb = t;
}
