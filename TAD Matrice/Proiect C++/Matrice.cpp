#include "Matrice.h"

#include <exception>
#include <stdexcept>
#include <stdlib.h>

using namespace std;
int Matrice::hash(int linie, int coloana, int pas) const {
	int poz = (abs(linie * coloane + coloana) + pas * pas) % capacitate;
	return poz;
}
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

Matrice::Matrice(int nrLinii, int nrColoane) {
	if (nrLinii <= 0 || nrColoane <= 0)
		throw invalid_argument("Dimensiuni invalide");

	linii = nrLinii;
	coloane = nrColoane;
	capacitate = 400000009; // un număr prim mare
	dimensiune = 0;
	tabela = new Triplet[capacitate];
	for (int i = 0; i < capacitate; i++) {
		tabela[i] = NULL_TRIPLET;
	}
}



int Matrice::nrLinii() const{
	return linii;
}


int Matrice::nrColoane() const{
	return coloane;
}


TElem Matrice::element(int i, int j) const{
	if (i < 0 || i >= linii || j < 0 || j >= coloane)
		throw out_of_range("Pozitie invalida");

	int p = pozitie(i, j);
	if (p == -1)
		return NULL_TELEMENT;
	return tabela[p].valoare;
}



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



