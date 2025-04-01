#include "Colectie.h"
#include <iostream>
using namespace std;

Colectie::Colectie() : size(0) {}

void Colectie::adaugaBancnota(int valoare, int numar) {
    for (int i = 0; i < size; i++) {
        if (valori[i] == valoare) {
            cantitati[i] += numar;
            return;
        }
    }
    valori[size] = valoare;
    cantitati[size] = numar;
    size++;
}

bool Colectie::retrageSuma(int suma, int bancnoteRetrase[][2], int &numarTipuri) {
    numarTipuri = 0;
    int tempCantitati[10];
    for (int i = 0; i < size; i++) {
        tempCantitati[i] = cantitati[i];
    }

    for (int i = 0; i < size; i++) {
        int valoare = valori[i];
        int necesar = suma / valoare;
        if (necesar > tempCantitati[i]) {
            necesar = tempCantitati[i];
        }
        if (necesar > 0) {
            bancnoteRetrase[numarTipuri][0] = valoare;
            bancnoteRetrase[numarTipuri][1] = necesar;
            numarTipuri++;
            suma -= necesar * valoare;
            tempCantitati[i] -= necesar;
        }
    }
    if (suma == 0) {
        for (int i = 0; i < size; i++) {
            cantitati[i] = tempCantitati[i];
        }
        return true;
    }
    return false;
}

void Colectie::afiseazaBancnote() {
    cout << "Bancnote disponibile:\n";
    for (int i = 0; i < size; i++) {
        cout << valori[i] << " RON: " << cantitati[i] << " exemplare\n";
    }
}
