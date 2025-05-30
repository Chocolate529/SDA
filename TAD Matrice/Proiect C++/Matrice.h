#pragma once

typedef int TElem;

class IteratorMatrice;
#define NULL_TELEMENT 0
struct Triplet {
	int linie;
	int coloana;
	TElem valoare;
};
class Matrice {

private:
	int linii, coloane;
	Triplet* tabela;
	int capacitate;
	int dimensiune;
	const Triplet NULL_TRIPLET = { -1, -1, NULL_TELEMENT };
	int hash(int linie, int coloana, int pas) const ;
	int pozitie(int linie, int coloana) const;
	void adauga(int linie, int coloana, TElem valoare);
public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice(){};

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem e);
	IteratorMatrice iterator(int linie) const;

};


class IteratorMatrice {
	friend class Matrice;

private:
	const Matrice& matrice;
	int linie;
	int coloana_curenta;

	IteratorMatrice(const Matrice& m, int linie);

public:
	void prim();               // se poziționează pe prima coloană
	void urmator();           // trece la următoarea coloană
	bool valid() const;       // verifică dacă iteratorul e valid
	TElem element() const;    // returnează elementul de pe linie, coloană
};




