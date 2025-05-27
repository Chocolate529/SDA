#include "IteratorMultime.h"
#include <stdexcept>

#define MAX_HEIGHT 100

// Add these private members to IteratorMultime in the header:
// int* stack;
// int stackSize;

IteratorMultime::IteratorMultime(const Multime& m) : mult(m) {
	stack = new int[MAX_HEIGHT];
	stackSize = 0;
	prim();
}

IteratorMultime::~IteratorMultime() {
	delete[] stack;
}

void IteratorMultime::prim() {
	stackSize = 0;
	int cur = mult.radacina;
	while (cur != -1) {
		stack[stackSize++] = cur;
		cur = mult.noduri[cur].st;
	}
}

void IteratorMultime::urmator() {
	if (!valid())
		throw std::exception();
	int node = stack[--stackSize];
	int cur = mult.noduri[node].dr;
	while (cur != -1) {
		stack[stackSize++] = cur;
		cur = mult.noduri[cur].st;
	}
}

bool IteratorMultime::valid() const {
	return stackSize > 0;
}

TElem IteratorMultime::element() const {
	if (!valid())
		throw std::exception();
	return mult.noduri[stack[stackSize - 1]].e;
}