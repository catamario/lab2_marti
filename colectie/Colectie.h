#ifndef COLECTIE_H
#define COLECTIE_H

const int MAX_ELEMS = 100;

typedef int TElem;

class Colectie {
private:
    TElem elems[MAX_ELEMS]; // fiecare bancnota este un element
    int size; // numarul total de bancnote

public:
    Colectie(); // constructor

    void add(TElem elem); // adauga o bancnota (o aparitie)

    bool remove(TElem elem); // sterge o aparitie daca exista

    bool search(TElem elem); // verifica daca o valoare exista in colectie

    int getSize(); // returneaza numarul total de bancnote

    int nrOccurrences(TElem elem); // returneaza cate bancnote de o anumita valoare exista

    int getAt(int position); // returneaza elementul de pe o pozitie (pentru parcurgere/afisare)
};

#endif
