#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
    return e1 <= e2;
}

//theta(1)
Colectie::Colectie() {
    capacitate = 10;
    noduri = new Nod[capacitate];
    prim = -1;
    ultim = -1;
    primLiber = 0;
    lungime = 0;

    for (int i = 0; i < capacitate - 1; i++)
        noduri[i].urm = i + 1;
    noduri[capacitate - 1].urm = -1;
}

//Theta(n)
void Colectie::redimensionare() {
    int newCap = capacitate * 2;
    Nod* newNoduri = new Nod[newCap];

    for (int i = 0; i < capacitate; i++)
        newNoduri[i] = noduri[i];

    for (int i = capacitate; i < newCap - 1; i++)
        newNoduri[i].urm = i + 1;
    newNoduri[newCap - 1].urm = -1;

    primLiber = capacitate;
    capacitate = newCap;
    delete[] noduri;
    noduri = newNoduri;
}

//Theta(n)
int Colectie::aloca() {
    if (primLiber == -1)
        redimensionare();
    int i = primLiber;
    primLiber = noduri[primLiber].urm;
    return i;
}

//Theta(1)
void Colectie::dealoca(int i) {
    noduri[i].urm = primLiber;
    primLiber = i;
}

//Theta(1)
int Colectie::creeazaNod(TElem e) {
    int i = aloca();
    noduri[i].element = e;
    noduri[i].urm = -1;
    noduri[i].prec = -1;
    return i;
}


//Best Case: Theta(1)
//WorstCase: Theta(n)
//AverageCase: O(n)
void Colectie::adauga(TElem e) {
    int nou = creeazaNod(e);
    if (prim == -1) {
        prim = nou;
        ultim = nou;
    } else {
        int p = prim;
        int ant = -1;

        while (p != -1 && rel(noduri[p].element, e)) {
            ant = p;
            p = noduri[p].urm;
        }

        if (ant == -1) {
            noduri[nou].urm = prim;
            noduri[prim].prec = nou;
            prim = nou;
        } else {
            noduri[nou].urm = noduri[ant].urm;
            noduri[nou].prec = ant;
            noduri[ant].urm = nou;

            if (noduri[nou].urm != -1)
                noduri[noduri[nou].urm].prec = nou;
            else
                ultim = nou;
        }
    }
    lungime++;
}

//BestCase: Theta(1)
//WorstCase: Theta(n)
//AverageCase: O(n)
bool Colectie::sterge(TElem e) {
    int p = prim;
    while (p != -1 && noduri[p].element != e)
        p = noduri[p].urm;

    if (p == -1)
        return false;

    if (p == prim)
        prim = noduri[p].urm;
    else
        noduri[noduri[p].prec].urm = noduri[p].urm;

    if (p == ultim)
        ultim = noduri[p].prec;
    else if (noduri[p].urm != -1)
        noduri[noduri[p].urm].prec = noduri[p].prec;

    dealoca(p);
    lungime--;
    return true;
}


//BestCase: Theta(1)
//WorstCase: Theta(n)
//AverageCase: O(n)
bool Colectie::cauta(TElem elem) const {
    int p = prim;
    while (p != -1) {
        if (noduri[p].element == elem)
            return true;
        p = noduri[p].urm;
    }
    return false;
}

//Theta(n)
int Colectie::nrAparitii(TElem elem) const {
    int p = prim;
    int aparitii = 0;
    while (p != -1) {
        if (noduri[p].element == elem)
            aparitii++;
        p = noduri[p].urm;
    }
    return aparitii;
}

//Theta(1)
int Colectie::dim() const {
    return lungime;
}

//Theta(1)
bool Colectie::vida() const {
    return lungime == 0;
}

//Theta(1)
IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}

//Theta(1)
Colectie::~Colectie() {
    delete[] noduri;
}

//Theta(n)
int Colectie::eliminaToateAparitiile(TElem elem) {
    int p = prim;
    int eliminari = 0;

    while (p != -1) {
        if (noduri[p].element == elem) {
            int deSters = p;
            p = noduri[p].urm;

            if (deSters == prim)
                prim = noduri[deSters].urm;
            else
                noduri[noduri[deSters].prec].urm = noduri[deSters].urm;

            if (deSters == ultim)
                ultim = noduri[deSters].prec;
            else if (noduri[deSters].urm != -1)
                noduri[noduri[deSters].urm].prec = noduri[deSters].prec;

            dealoca(deSters);
            lungime--;
            eliminari++;
        } else {
            p = noduri[p].urm;
        }
    }

    return eliminari;
}