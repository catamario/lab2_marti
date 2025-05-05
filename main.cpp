#include "atm/ATM.h"

int main() {
    ATM atm;
    int optiune;

    do {
        cout << "\n===== MENIU ATM =====\n";
        cout << "1. Adauga bancnote\n";
        cout << "2. Retrage bani\n";
        cout << "3. Afiseaza bancnote disponibile\n";
        cout << "4. Afiseaza tranzactii\n";
        cout << "0. Iesire\n";
        cout << "Alege optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1: {
                int val, nr;
                cout << "Valoare bancnota: ";
                cin >> val;
                cout << "Numar bancnote: ";
                cin >> nr;
                atm.adaugaBancnote(val, nr);
                break;
            }
            case 2: {
                int suma;
                cout << "Suma de retras: ";
                cin >> suma;
                atm.retrageBani(suma);
                break;
            }
            case 3:
                atm.afiseazaBancnoteDisponibile();
            break;
            case 4:
                atm.afiseazaTranzactii();
            break;
            case 0:
                cout << "Iesire...\n";
            break;
            default:
                cout << "Optiune invalida.\n";
        }
    } while (optiune != 0);

    return 0;
}
