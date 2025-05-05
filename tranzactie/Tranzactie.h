#ifndef TRANZACTIE_H
#define TRANZACTIE_H

#include <iostream>
using namespace std;

class Tranzactie {
private:
    int id; // id-ul tranzactiei
    int suma; // suma retrasa
    int valori[10]; // valorile bancnotelor
    int cantitati[10]; // numarul fiecarei bancnote
    int numarTipuri; // cate tipuri de bancnote au fost folosite

public:
    Tranzactie(int id, int suma, int v[], int c[], int tipuri); // constructor
    void afiseaza(); // afiseaza tranzactia
};

#endif
