#include "Matrice.h"

#include <exception>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

//Theta(1)
int Matrice::hash(int linie, int coloana, int pas) const {
	int poz = (abs(linie * coloane + coloana) + pas * pas) % capacitate;
	return poz;
}
//BestCase : Theta(1)
//WorstCase : Theta(Capacitate)
//AverageCase : O(capacitate)
int Matrice::pozitie(int linie, int coloana) const {
	for (int i = 0; i < capacitate; ++i) {
		int poz = hash(linie, coloana, i);
		if (tabela[poz].valoare == NULL_TELEMENT && tabela[poz].linie == -1)
			return -1;
		if (tabela[poz].linie == linie && tabela[poz].coloana == coloana)
			return poz;
	}
	return -1;
}

//BestCase : Theta(1)
//WorstCase : Theta(Capacitate)
//AverageCase : O(capacitate)
void Matrice::adauga(int linie, int coloana, TElem val) {
	for (int i = 0; i < capacitate; ++i) {
		int poz = hash(linie, coloana, i);
		if (tabela[poz].valoare == NULL_TELEMENT && tabela[poz].linie == -1) {
			tabela[poz] = { linie, coloana, val };
			dimensiune++;
			return;

		}
	}
	throw runtime_error("Tabela plina!");
}
//Theta(capacitate)
Matrice::Matrice(int nrLinii, int nrColoane) {
	if (nrLinii <= 0 || nrColoane <= 0)
		throw invalid_argument("Dimensiuni invalide");

	linii = nrLinii;
	coloane = nrColoane;
	capacitate = linii*coloane;
	dimensiune = 0;
	tabela = new Triplet[capacitate];
	for (int i = 0; i < capacitate; i++) {
		tabela[i] = NULL_TRIPLET;
	}
}


//Theta(1)
int Matrice::nrLinii() const{
	return linii;
}

//Theta(1)
int Matrice::nrColoane() const{
	return coloane;
}

//O(capacitate)
TElem Matrice::element(int i, int j) const{
	if (i < 0 || i >= linii || j < 0 || j >= coloane)
		throw out_of_range("Pozitie invalida");

	int p = pozitie(i, j);
	if (p == -1)
		return NULL_TELEMENT;
	return tabela[p].valoare;
}


//O(capacitate)
TElem Matrice::modifica(int i, int j, TElem e) {
	if (i < 0 || i >= linii || j < 0 || j >= coloane)
		throw out_of_range("Pozitie invalida");

	int p = pozitie(i, j);
	if (p != -1) {
		TElem vechi = tabela[p].valoare;
		if (e == NULL_TELEMENT) {
			tabela[p] = NULL_TRIPLET;
			dimensiune--;
		} else {
			tabela[p].valoare = e;
		}
		return vechi;
	} else {
		if (e != NULL_TELEMENT)
			adauga(i, j, e);
		return NULL_TELEMENT;
	}
}

//Theta(1)
IteratorMatrice Matrice::iterator(int linie) const {
	if (linie < 0 || linie >= linii)
		throw std::exception();
	return IteratorMatrice(*this, linie);
}

//Theta(1)
IteratorMatrice::IteratorMatrice(const Matrice& m, int linie) : matrice(m), linie(linie), coloana_curenta(0) {}

//Theta(1)
void IteratorMatrice::prim() {
	coloana_curenta = 0;
}

//Theta(1)
void IteratorMatrice::urmator() {
	++coloana_curenta;
}

//Theta(1)
bool IteratorMatrice::valid() const {
	return coloana_curenta < matrice.nrColoane();
}

//Theta(1)
TElem IteratorMatrice::element() const {
	if (!valid())
		throw std::exception();
	return matrice.element(linie, coloana_curenta);
}