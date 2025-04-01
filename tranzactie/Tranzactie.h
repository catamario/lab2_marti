#ifndef TRANZACTIE_H
#define TRANZACTIE_H

#include <iostream>
using namespace std;

class Tranzactie {
public:
    int id, suma;
    int bancnoteFolosite[10][2];
    int numarTipuri;
    Tranzactie(int id, int suma, int bancnoteFolosite[][2], int numarTipuri);
    void afiseazaTranzactie();
};

#endif