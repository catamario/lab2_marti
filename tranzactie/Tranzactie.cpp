#include "Tranzactie.h"
#include <iostream>
using namespace std;

Tranzactie::Tranzactie(int id, int suma, int bancnoteFolosite[][2], int numarTipuri) : id(id), suma(suma), numarTipuri(numarTipuri) {
    for (int i = 0; i < numarTipuri; i++) {
        this->bancnoteFolosite[i][0] = bancnoteFolosite[i][0];
        this->bancnoteFolosite[i][1] = bancnoteFolosite[i][1];
    }
}

void Tranzactie::afiseazaTranzactie() {
    cout << "Tranzactie " << id << ": " << suma << " RON folosind:\n";
    for (int i = 0; i < numarTipuri; i++) {
        cout << bancnoteFolosite[i][1] << " x " << bancnoteFolosite[i][0] << " RON\n";
    }
}