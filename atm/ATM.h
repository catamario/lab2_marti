#ifndef ATM_H
#define ATM_H

#include "../colectie/Colectie.h"
#include "../tranzactie/Tranzactie.h"

class ATM {
private:
    Colectie colectie; // stocheaza toate bancnotele disponibile
    Tranzactie* tranzactii[100]; // vector de pointeri la tranzactii
    int tranzactieID; // contor unic pentru tranzactii
    int tranzactieCount; // numarul total de tranzactii inregistrate

public:
    ATM(); // constructor
    ~ATM(); // destructor

    void adaugaBancnote(int valoare, int numar); // adauga un numar de bancnote de o anumita valoare

    void retrageBani(int suma); // retrage suma daca e posibil, construind o tranzactie

    void afiseazaTranzactii(); // afiseaza toate tranzactiile inregistrate

    void afiseazaBancnoteDisponibile(); // afiseaza toate bancnotele disponibile in ATM
};

#endif
