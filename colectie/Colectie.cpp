#include "Colectie.h"

Colectie::Colectie() {
    size = 0;
}

void Colectie::add(TElem elem) {
    if (size < MAX_ELEMS) {
        elems[size++] = elem; // adauga bancnota la final
    }
}

bool Colectie::remove(TElem elem) {
    for (int i = 0; i < size; i++) {
        if (elems[i] == elem) {
            elems[i] = elems[size - 1]; // inlocuieste cu ultima bancnota
            size--;
            return true; // eliminare reusita
        }
    }
    return false; // nu a fost gasita bancnota
}

bool Colectie::search(TElem elem) {
    for (int i = 0; i < size; i++) {
        if (elems[i] == elem)
            return true;
    }
    return false;
}

int Colectie::getSize() {
    return size;
}

int Colectie::nrOccurrences(TElem elem) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (elems[i] == elem)
            count++;
    }
    return count;
}

int Colectie::getAt(int position) {
    if (position >= 0 && position < size)
        return elems[position];
    return -1;
}
