#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>
enum {
	INITIAL_CAPACITY = 2,
	INITIAL_SIZE = 0,

};
#define ALPHA 0.7
#define BETA 0.3
using namespace std;

//o posibila relatie
bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) {
		return true;
	}
	return false;

}

Multime::Multime() {
	this->size = INITIAL_SIZE;
	this->capacity = INITIAL_CAPACITY;
	this->data = new TElem[this->capacity];
}

void Multime::resize(int capacity) {
	TElem *newData = new TElem[capacity];
	for (int i = 0; i < this->size; i++) {
		newData[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newData;
	this->capacity = capacity;
}

//favorabil: Theta(1)
//devaforabil: Theta(n)
//Mediu: O(n)
//Overall: O(n)
bool Multime::adauga(TElem elem) {
	if (this->size >= ALPHA * this->capacity ) {
		resize(this->capacity * 2);
	}
	if (!cauta(elem)) {
		int i = this->size-1;
		this->size++;
		while (i >=0 and !rel(this->data[i], elem) ) {
			this->data[i+1] = this->data[i];
			i--;
		}
		this->data[i+1] = elem;
		return true;
	}
	return false;
}

//favorabil: Theta(n)
//defavorabil: Theta(n)
//Mediu: Theta(n)
//Overall: O(n)
bool Multime::sterge(TElem elem) {
	for (int i = 0; i < this->size; i++) {
			if (this->data[i] == elem) {
				for (int j = i; j < this->size-1; j++) {
					this->data[j] = this->data[j+1];
				}
				this->size--;
				if (this->size <= BETA * this->capacity) {
					resize(this->capacity/2);
				}
				return true;
			}
	}
	return false;
}

//favorabil: Theta(1)
//defavorabil: Theta(n)
//Mediu: Theta(n)
//Overall: O(n)
bool Multime::cauta(TElem elem) const {
	for (int i = 0; i < this->size; i++) {
		if (this->data[i] == elem) {
			return true;
		}
	}
	return false;
}

//favorabil: Theta(1)
//defavorabil: Theta(1)
//Mediu: Theta(1)
//Overvall: Theta(1)
int Multime::dim() const {
	return this->size;
}


//favorabil: Theta(1)
//defavorabil: Theta(1)
//Mediu: Theta(1)
//Overvall: Theta(1)
bool Multime::vida() const {
	return this->size == 0;
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


Multime::~Multime() {
	/* de adaugat */
}






