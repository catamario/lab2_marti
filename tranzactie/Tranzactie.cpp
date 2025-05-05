#include "Tranzactie.h"

Tranzactie::Tranzactie(int id, int suma, int v[], int c[], int tipuri) {
    this->id = id;
    this->suma = suma;
    this->numarTipuri = tipuri;
    for (int i = 0; i < tipuri; i++) {
        valori[i] = v[i];
        cantitati[i] = c[i];
    }
}

void Tranzactie::afiseaza() {
    cout << "Tranzactie #" << id << ": Suma " << suma << " RON\n";
    for (int i = 0; i < numarTipuri; i++) {
        cout << "  " << cantitati[i] << " x " << valori[i] << " RON\n";
    }
}
