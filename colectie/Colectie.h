#ifndef COLECTIE_H
#define COLECTIE_H

#include <iostream>
using namespace std;

class Colectie {
private:
    int valori[10];
    int cantitati[10];
    int size;
public:
    Colectie();
    void adaugaBancnota(int valoare, int numar);
    bool retrageSuma(int suma, int bancnoteRetrase[][2], int &numarTipuri);
    void afiseazaBancnote();
};

#endif