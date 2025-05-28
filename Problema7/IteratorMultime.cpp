#include "IteratorMultime.h"
#include <stdexcept>

#define MAX_HEIGHT 100

// Add these private members to IteratorMultime in the header:
// int* stack;
// int stackSize;

//O(h)
IteratorMultime::IteratorMultime(const Multime& m) : mult(m) {
	stack = new int[MAX_HEIGHT];
	stackSize = 0;
	prim();
}

//Theta(1)
IteratorMultime::~IteratorMultime() {
	delete[] stack;
}

//Best Case: theta(1)
//worst Case: theta(h)
//Average Case: O(h)
void IteratorMultime::prim() {
	stackSize = 0;
	int cur = mult.radacina;
	while (cur != -1) {
		stack[stackSize++] = cur;
		cur = mult.noduri[cur].st;
	}
}

//Best Case: Theta(1)
//Worst Case: O(h)
//Average Case: O(h)
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
//Theta(1)
bool IteratorMultime::valid() const {
	return stackSize > 0;
}
//Theta(1)
TElem IteratorMultime::element() const {
	if (!valid())
		throw std::exception();
	return mult.noduri[stack[stackSize - 1]].e;
}