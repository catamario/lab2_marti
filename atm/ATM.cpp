#include "ATM.h"
#include <iostream>
using namespace std;

ATM::ATM() {
    tranzactieID = 1;
    tranzactieCount = 0;
}

ATM::~ATM() {
    for (int i = 0; i < tranzactieCount; i++) {
        delete tranzactii[i];
    }
}

void ATM::adaugaBancnote(int valoare, int numar) {
    for (int i = 0; i < numar; i++) {
        colectie.add(valoare); // adauga bancnota in colectie
    }
}

void ATM::retrageBani(int suma) {
    int valoriUnice[10];      // array pentru valorile unice ale bancnotelor
    int frecvente[10];        // array pentru frecventa fiecarei bancnote
    int tipuri = 0;

    // Construim valorile unice si frecventele lor
    for (int i = 0; i < colectie.getSize(); i++) {
        int val = colectie.getAt(i);
        bool found = false;
        for (int j = 0; j < tipuri; j++) {
            if (valoriUnice[j] == val) {
                frecvente[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            valoriUnice[tipuri] = val;
            frecvente[tipuri] = 1;
            tipuri++;
        }
    }

    // Sortam valorile descrescator (Bubble Sort simplu)
    for (int i = 0; i < tipuri - 1; i++) {
        for (int j = i + 1; j < tipuri; j++) {
            if (valoriUnice[i] < valoriUnice[j]) {
                swap(valoriUnice[i], valoriUnice[j]);
                swap(frecvente[i], frecvente[j]);
            }
        }
    }

    // Incercam sa retragem suma
    int sumaRamasa = suma;
    int bancnoteFolositeValori[10];
    int bancnoteFolositeCant[10];
    int tipuriFolosite = 0;

    for (int i = 0; i < tipuri && sumaRamasa > 0; i++) {
        int val = valoriUnice[i];
        int maxFolosite = sumaRamasa / val;
        int folosite = (maxFolosite <= frecvente[i]) ? maxFolosite : frecvente[i];
        if (folosite > 0) {
            bancnoteFolositeValori[tipuriFolosite] = val;
            bancnoteFolositeCant[tipuriFolosite] = folosite;
            tipuriFolosite++;
            sumaRamasa -= folosite * val;
        }
    }

    if (sumaRamasa == 0) {
        // Stergem bancnotele folosite din colectie
        for (int i = 0; i < tipuriFolosite; i++) {
            for (int j = 0; j < bancnoteFolositeCant[i]; j++) {
                colectie.remove(bancnoteFolositeValori[i]);
            }
        }

        // Cream si salvam tranzactia
        tranzactii[tranzactieCount++] = new Tranzactie(tranzactieID++, suma, bancnoteFolositeValori, bancnoteFolositeCant, tipuriFolosite);
        cout << "Retragere reusita. S-au folosit urmatoarele bancnote:\n";
        for (int i = 0; i < tipuriFolosite; i++) {
            cout << bancnoteFolositeCant[i] << " x " << bancnoteFolositeValori[i] << " RON\n";
        }
    } else {
        cout << "Retragere esuata. Nu exista suficiente bancnote pentru suma ceruta.\n";
    }
}

void ATM::afiseazaTranzactii() {
    if (tranzactieCount == 0) {
        cout << "Nu exista tranzactii inregistrate.\n";
        return;
    }
    for (int i = 0; i < tranzactieCount; i++) {
        tranzactii[i]->afiseaza();
    }
}

void ATM::afiseazaBancnoteDisponibile() {
    int valoriUnice[10];
    int frecvente[10];
    int tipuri = 0;

    // Construim valorile unice si frecventele lor
    for (int i = 0; i < colectie.getSize(); i++) {
        int val = colectie.getAt(i);
        bool found = false;
        for (int j = 0; j < tipuri; j++) {
            if (valoriUnice[j] == val) {
                frecvente[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            valoriUnice[tipuri] = val;
            frecvente[tipuri] = 1;
            tipuri++;
        }
    }

    if (tipuri == 0) {
        cout << "ATM-ul nu are bancnote disponibile.\n";
        return;
    }

    // Afisam bancnotele disponibile
    cout << "Bancnote disponibile:\n";
    for (int i = 0; i < tipuri; i++) {
        cout << frecvente[i] << " x " << valoriUnice[i] << " RON\n";
    }
}
