#pragma once 

#include <vector>
#include <random>
#include <deque>
class ARXModel {

    std::vector<double> A;
    std::vector<double> B;
    int opoznienie;
    double zaklocenie=0;

    std::deque<double> wejscia;     
    std::deque<double> wyjscia;     
    std::default_random_engine generator;
    std::normal_distribution<double> rozklad;

public:
    ARXModel();
    ARXModel(const std::vector<double>& wspA, const std::vector<double>& wspB, int opoz, double zakl);
    std::vector<double> getVectorA();
    std::vector<double> getVectorB();
    int getOpoznienie();
    void setVectorA(std::vector<double> A);
    void setVectorB(std::vector<double> B);
    void setZaklocenie(double zakl);
    double getZaklocenie();
    void setOpoznienie(int o);
    double symulacja(double sygnal);
    void reset();
    double getVectorA(int index);
    double getVectorB(int index);

};
