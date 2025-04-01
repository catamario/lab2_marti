#include "atm/ATM.h"
#include <iostream>
using namespace std;

int main() {
    ATM atm;
    atm.adaugaBancnote(100, 50);
    atm.adaugaBancnote(50, 45);
    atm.adaugaBancnote(10, 100);

    int optiune;
    do {
        cout << "\nMeniu ATM:\n";
        cout << "1. Afisare bancnote disponibile\n";
        cout << "2. Retragere bani\n";
        cout << "3. Afisare istoric tranzactii\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> optiune;

        if (optiune == 1) {
            atm.afiseazaBancnoteDisponibile();
        } else if (optiune == 2) {
            int suma;
            cout << "Introdu suma: ";
            cin >> suma;
            atm.retrageBani(suma);
        } else if (optiune == 3) {
            atm.afiseazaTranzactii();
        }
    } while (optiune != 0);

    return 0;
}
