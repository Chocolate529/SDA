#include "IteratorMultime.h"

#include <stdexcept>

#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	this->current = m.first;
}


void IteratorMultime::prim() {
	this->current = this->multime.first;

}


void IteratorMultime::urmator() {
	if (valid()) {
		this->current = this->current->next;
	}
}


TElem IteratorMultime::element() const {
	if (valid()) {
		return this->current->data;
	}
	// If not valid, throw an exception or return an error value
	throw std::out_of_range("Iterator is not valid.");
}

bool IteratorMultime::valid() const {
	return this->current != nullptr;
}
