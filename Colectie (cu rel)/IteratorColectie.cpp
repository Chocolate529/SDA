#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

//Theta(1)
IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	curent = col.prim;
}

//Theta(1)
void IteratorColectie::prim() {
	curent = col.prim;
}

//Theta(1)
void IteratorColectie::urmator() {
	if (!valid())
		throw std::exception();
	curent = col.noduri[curent].urm;
}

//Theta(1)
bool IteratorColectie::valid() const {
	return curent != -1;
}

//Theta(1)
TElem IteratorColectie::element() const {
	if (!valid())
		throw std::exception();
	return col.noduri[curent].element;
}