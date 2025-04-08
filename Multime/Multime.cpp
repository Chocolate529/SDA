#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime() {
	this->size = 0;
	this->first = nullptr;
	this->last = nullptr;
}


bool Multime::adauga(TElem elem) {
	if (!cauta(elem)) {
		NOD* new_node = new NOD;
		new_node->data = elem;
		new_node->next = nullptr;

		if (this->first == nullptr) { // Set is empty
			this->first = new_node;
		} else {
			this->last->next = new_node;
		}

		this->last = new_node;
		this->size++;
		return true;
	}
	return false;
}


bool Multime::sterge(TElem elem) {
	NOD* current = this->first;
	NOD* previous = nullptr;

	while (current != nullptr) {
		if (current->data == elem) {
			if (previous == nullptr) { // Element is first
				this->first = current->next;
			} else {
				previous->next = current->next;
			}

			if (current == this->last) { // Element is last
				this->last = previous;
			}

			delete current;
			this->size--;
			return true;
		}
		previous = current;
		current = current->next;
	}
	return false;
}


bool Multime::cauta(TElem elem) const {
	NOD* current = this->first;
	while (current != nullptr) {
		if (current->data == elem) {
			return true;
		}
		current = current->next;
	}
	return false;
}


int Multime::dim() const {
	return this->size;
}

bool Multime::vida() const {
	return this->first == nullptr;
}


Multime::~Multime() {
	NOD* current = this->first;
	while (current != nullptr) {
		NOD* next = current->next;
		delete current;
		current = next;
	}
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

