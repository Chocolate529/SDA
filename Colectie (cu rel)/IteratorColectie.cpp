#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	curent = col.prim;
}

void IteratorColectie::prim() {
	curent = col.prim;
}

void IteratorColectie::urmator() {
	if (!valid())
		throw std::exception();
	curent = col.noduri[curent].urm;
}

bool IteratorColectie::valid() const {
	return curent != -1;
}

TElem IteratorColectie::element() const {
	if (!valid())
		throw std::exception();
	return col.noduri[curent].element;
}