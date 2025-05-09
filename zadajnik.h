#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

enum class TypSygnalu
{
    SKOK,
    SINUS,
    PROST
};

class Zadajnik
{
    double amplituda = 0;
	double okres = 0;
	double wypelnienie = 0;
    double skladowaStala;
    double czasAktywacji;
    TypSygnalu typ;

public:
    Zadajnik();
    Zadajnik(double a, double o, double wy, double skl, int czAkt);
    void setAmplituda(double a);
	void setOkres(double o);
	void setWypelnienie(double wy);
    void setTyp(TypSygnalu t);
    void setSkladowa(double skl);
    void setCzasAktywacji(int czAkt);
	double skok();
	double sinus(double czas);
	double prostokat(double czas);
    double generujSygnal(double czas, TypSygnalu t);
    TypSygnalu getTyp();

    double getAmplituda() const { return amplituda; }
    double getOkres() const { return okres; }
    double getWypelnienie() const { return wypelnienie; }
    double getSkladowaStala() const { return skladowaStala; }
    double getCzasAktywacji() const { return czasAktywacji; }
    TypSygnalu getTyp() const { return typ; }
};
