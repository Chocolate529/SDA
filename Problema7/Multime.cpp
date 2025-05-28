#include "Multime.h"
#include <stdexcept>
#include "IteratorMultime.h"
#define CAPACITATE_INITIALA 10
#include <stack>
bool rel(TElem a, TElem b) {
    return a < b;
}

//Theta(capacitate)
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

//Theta(capacitate)
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

//Theta(1)
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

//Best Case: Theta(1)
//Worst Case: Theta(h)
//Average Case: O(h)
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

//Best Case: Theta(1)
//Worst Case: Theta(h)
//Best Case: O(h)
int stergeRec(int curent, TElem e, Nod* noduri, int& primLiber, int& dim, bool& sters, Relatie rel) {
    if (curent == -1) return -1;

    if (noduri[curent].e == e) {
        sters = true;
        dim--;

        if (noduri[curent].st == -1 || noduri[curent].dr == -1) {
            int child = (noduri[curent].st != -1) ? noduri[curent].st : noduri[curent].dr;
            noduri[curent].st = primLiber;
            primLiber = curent;
            return child;
        }

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

//Best Case: Theta(1)
//Worst Case: Theta(h)
//Best Case: O(h)
bool Multime::sterge(TElem e) {
    bool sters = false;
    radacina = stergeRec(radacina, e, noduri, primLiber, dimensiune, sters, rel);
    return sters;
}

//Best Case: Theta(1)
//Worst Case: Theta(h)
//Best Case: O(h)
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

//Theta(1)
int Multime::dim() const {
    return dimensiune;
}

//Theta(1)
bool Multime::vida() const {
    return dimensiune == 0;
}

//Theta(1)
IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}

//Theta(1)
Multime::~Multime() {
    delete[] noduri;
}

//Theta(dim)
int Multime::diferențaMaxMin() const {
    if (dimensiune == 0)
        return -1;

    int minVal = noduri[radacina].e;
    int maxVal = noduri[radacina].e;

    std::stack<int> stack;
    if (radacina != -1)
        stack.push(radacina);

    while (!stack.empty()) {
        int index  = stack.top();
        stack.pop();

        TElem val = noduri[index].e;
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;

        if (noduri[index].st != -1)
            stack.push(noduri[index].st);
        if (noduri[index].dr != -1)
            stack.push(noduri[index].dr);
    }

    return maxVal - minVal;
}
