#include "IteratorMultime.h"

#include <iostream>
#include <stdexcept>

#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m): mult(m) {
	this->pozitie = 0;
}

TElem IteratorMultime::element() const {
	if (valid())
		return this->mult.data[this->pozitie];
	throw std::exception();
}

bool IteratorMultime::valid() const {
	return this->pozitie < this->mult.size;
}

void IteratorMultime::urmator() {
	this->pozitie++;
}

void IteratorMultime::prim() {
	this->pozitie = 0;
}

