#include "zadajnik.h"

Zadajnik::Zadajnik() : amplituda(2.0), okres(1.0), wypelnienie(0.5), skladowaStala(2.0), czasAktywacji(1.0), typ(TypSygnalu::SKOK) {}

Zadajnik::Zadajnik(double a, double o, double wy, double skl, int czAkt) : typ(TypSygnalu::SKOK)
{
    setAmplituda(a);
	setOkres(o);
	setWypelnienie(wy);
    setSkladowa(skl);
    setCzasAktywacji(czAkt);
}

void Zadajnik::setAmplituda(double a)
{
    a > 0 ? this->amplituda = a : this->amplituda = 0;
}

void Zadajnik::setOkres(double o)
{
	o > 0 ? this->okres = o : this->okres = 0;
}

void Zadajnik::setWypelnienie(double wy)
{
	wy > 0 ? this->wypelnienie = wy : this->wypelnienie = 0;
}

// double Zadajnik::skok()
// {
// 	return this->wartosc;
// }

// double Zadajnik::sinus(double czas)
// {
//     return wartosc * sin((fmod(czas, okres) * 2 * M_PI) / okres);
// }

// double Zadajnik::prostokat(double czas)
// {
//     return fmod(czas, okres) < (wypelnienie * okres) ? wartosc : 0.0;
// }

double Zadajnik::generujSygnal(double czas, TypSygnalu t)
{
    switch(t)
    {
    case TypSygnalu::SKOK:
        return czasAktywacji <= czas ? this->skladowaStala : 0;
        break;
    case TypSygnalu::SINUS:
        return amplituda * sin((fmod(czas, okres) * 2 * M_PI) / okres) + skladowaStala;
        break;
    case TypSygnalu::PROST:
        return fmod(czas, okres) < (wypelnienie * okres) ? amplituda + skladowaStala : skladowaStala;
        break;
    }
    return 0;
}

TypSygnalu Zadajnik::getTyp()
{
    return typ;
}

void Zadajnik::setTyp(TypSygnalu t)
{
    this->typ = t;
}

void Zadajnik::setSkladowa(double skl)
{
    this->skladowaStala = skl;
}

void Zadajnik::setCzasAktywacji(int czAkt)
{
    this->czasAktywacji = czAkt / 1000.0;
}
