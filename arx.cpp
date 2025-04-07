#include "arx.h"
#include <QDebug>
ARXModel::ARXModel(): A({-0.4}), B({0.6}), opoznienie(1), zaklocenie(0){}

ARXModel::ARXModel(const std::vector<double>& wspA, const std::vector<double>& wspB, int opoz,double zakl)
    : A(wspA), B(wspB), opoznienie(opoz), zaklocenie(zakl),
    generator(std::random_device{}()),
    rozklad(0, 0.01)
{
    wejscia = std::deque<double>(wspB.size() + opoznienie, 0.0);
    wyjscia = std::deque<double>(wspA.size(), 0.0);

}

double ARXModel::symulacja(double noweWejscie) {
    
    wejscia.push_front(noweWejscie);

    if (wejscia.size() >B.size() +opoznienie) {
        wejscia.pop_back();
    }

 
    double Wyjscie = 0.0;


    for (size_t i = 0; i < B.size(); ++i) {
        if (i + opoznienie < wejscia.size()) {
            Wyjscie += B[i] * wejscia[i + opoznienie];
        }
    }

    
    for (size_t i = 0; i < A.size(); ++i) {
        if (i < wyjscia.size()) {
            Wyjscie -= A[i] * wyjscia[i];
        }
    }

    if (zaklocenie > 0) {
        Wyjscie += rozklad(generator) * zaklocenie;

    }
    wyjscia.push_front(Wyjscie);

    if (wyjscia.size() > A.size()) {
        wyjscia.pop_back();
    }

    return Wyjscie;
}

std::vector<double> ARXModel::getVectorA()
{
    return this->A;
}

std::vector<double> ARXModel::getVectorB()
{
    return this->B;
}

int ARXModel::getOpoznienie()
{
    return opoznienie;
}

void ARXModel::setZaklocenie(double zakl)
{
    this->zaklocenie=zakl;
}

void ARXModel::setVectorA(std::vector<double> A)
{
    this->A = A;
}

void ARXModel::setVectorB(std::vector<double> B)
{
    this->B = B;
}

void ARXModel::setOpoznienie(int o)
{
    o >= 0 ? this->opoznienie = o : opoznienie = 0;
}

double ARXModel::getZaklocenie()
{
    return zaklocenie;
}

void ARXModel::reset()
{
    wejscia.clear();
    wyjscia.clear();
}
double ARXModel::getVectorA(int index)
{
    return A[index];
}
double ARXModel::getVectorB(int index)
{
    return B[index];
}
