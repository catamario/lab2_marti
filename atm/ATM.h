#ifndef ATM_H
#define ATM_H

#include "../colectie/Colectie.h"
#include "../tranzactie/Tranzactie.h"

class ATM {
private:
    Colectie colectie;
    Tranzactie *tranzactii[100];
    int tranzactieID;
    int tranzactieCount;
public:
    ATM();
    ~ATM();
    void adaugaBancnote(int valoare, int numar);
    void retrageBani(int suma);
    void afiseazaTranzactii();
    void afiseazaBancnoteDisponibile();
};

#endif