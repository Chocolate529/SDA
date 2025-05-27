#include "Multime.h"
#include <stdexcept>
#include "IteratorMultime.h"
#define CAPACITATE_INITIALA 10

bool rel(TElem a, TElem b) {
    return a < b;
}

Multime::Multime() {
    capacitate = CAPACITATE_INITIALA;
    noduri = new Nod[capacitate];
    radacina = -1;
    primLiber = 0;
    dimensiune = 0;
    for (int i = 0; i < capacitate - 1; ++i)
        noduri[i].st = i + 1;
    noduri[capacitate - 1].st = -1;
}

void Multime::resize() {
    int newCap = capacitate * 2;
    Nod* newNoduri = new Nod[newCap];
    for (int i = 0; i < capacitate; ++i)
        newNoduri[i] = noduri[i];
    for (int i = capacitate; i < newCap - 1; ++i)
        newNoduri[i].st = i + 1;
    newNoduri[newCap - 1].st = -1;
    delete[] noduri;
    noduri = newNoduri;
    primLiber = capacitate;
    capacitate = newCap;
}

int Multime::creeazaNod(TElem e) {
    if (primLiber == -1)
        resize();
    int poz = primLiber;
    primLiber = noduri[primLiber].st;
    noduri[poz].e = e;
    noduri[poz].st = -1;
    noduri[poz].dr = -1;
    return poz;
}

bool Multime::adauga(TElem e) {
    if (radacina == -1) {
        radacina = creeazaNod(e);
        dimensiune++;
        return true;
    }
    int curent = radacina, parinte = -1;
    while (curent != -1) {
        if (noduri[curent].e == e)
            return false;
        parinte = curent;
        if (rel(e, noduri[curent].e))
            curent = noduri[curent].st;
        else
            curent = noduri[curent].dr;
    }
    int nou = creeazaNod(e);
    if (rel(e, noduri[parinte].e))
        noduri[parinte].st = nou;
    else
        noduri[parinte].dr = nou;
    dimensiune++;
    return true;
}

int stergeRec(int curent, TElem e, Nod* noduri, int& primLiber, int& dim, bool& sters, Relatie rel) {
    if (curent == -1) return -1;

    if (noduri[curent].e == e) {
        sters = true;
        dim--;

        // Handle nodes with at most one child
        if (noduri[curent].st == -1 || noduri[curent].dr == -1) {
            int child = (noduri[curent].st != -1) ? noduri[curent].st : noduri[curent].dr;
            noduri[curent].st = primLiber;
            primLiber = curent;
            return child;
        }

        // Handle nodes with two children
        int succ = noduri[curent].dr;
        while (noduri[succ].st != -1) succ = noduri[succ].st;
        noduri[curent].e = noduri[succ].e;
        noduri[curent].dr = stergeRec(noduri[curent].dr, noduri[succ].e, noduri, primLiber, dim, sters, rel);
        return curent;
    }

    if (rel(e, noduri[curent].e))
        noduri[curent].st = stergeRec(noduri[curent].st, e, noduri, primLiber, dim, sters, rel);
    else
        noduri[curent].dr = stergeRec(noduri[curent].dr, e, noduri, primLiber, dim, sters, rel);

    return curent;
}

bool Multime::sterge(TElem e) {
    bool sters = false;
    radacina = stergeRec(radacina, e, noduri, primLiber, dimensiune, sters, rel);
    return sters;
}

bool Multime::cauta(TElem elem) const {
    int curent = radacina;
    while (curent != -1) {
        if (noduri[curent].e == elem)
            return true;
        if (rel(elem, noduri[curent].e))
            curent = noduri[curent].st;
        else
            curent = noduri[curent].dr;
    }
    return false;
}

int Multime::dim() const {
    return dimensiune;
}

bool Multime::vida() const {
    return dimensiune == 0;
}
IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}
Multime::~Multime() {
    delete[] noduri;
}