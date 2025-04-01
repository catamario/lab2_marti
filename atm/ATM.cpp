#include "ATM.h"
#include <iostream>
using namespace std;

ATM::ATM() : tranzactieID(0), tranzactieCount(0) {}

ATM::~ATM() {
    for (int i = 0; i < tranzactieCount; i++) {
        delete tranzactii[i];
    }
}

void ATM::adaugaBancnote(int valoare, int numar) {
    colectie.adaugaBancnota(valoare, numar);
}

void ATM::retrageBani(int suma) {
    int bancnoteRetrase[10][2];
    int numarTipuri;
    if (colectie.retrageSuma(suma, bancnoteRetrase, numarTipuri)) {
        tranzactii[tranzactieCount++] = new Tranzactie(++tranzactieID, suma, bancnoteRetrase, numarTipuri);
        cout << "Tranzactie reusita!\n";
    } else {
        cout << "Fonduri insuficiente sau imposibil de oferit suma exacta!\n";
    }
}

void ATM::afiseazaTranzactii() {
    cout << "Istoric tranzactii:\n";
    for (int i = 0; i < tranzactieCount; i++) {
        tranzactii[i]->afiseazaTranzactie();
    }
}

void ATM::afiseazaBancnoteDisponibile() {
    colectie.afiseazaBancnote();
}
