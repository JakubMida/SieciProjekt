#ifndef ARXSTAN_H
#define ARXSTAN_H
#include <vector>
#include <random>
#include <deque>
struct arxStan{
    std::vector<double> A;
    std::vector<double> B;
    int opoznienie;
    double zaklocenie=0;

    std::deque<double> wejscia;
    std::deque<double> wyjscia;
    std::default_random_engine generator;
    std::normal_distribution<double> rozklad;
};

#endif // ARXSTAN_H
