#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>

using namespace std;

void testAll() {
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);

	m.modifica(1,1,5);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
	assert(m.element(1,2) == NULL_TELEMENT);


	IteratorMatrice it1 = m.iterator(2);
	it1.prim();

	int col = 0;
	while (it1.valid()) {
		assert(it1.element() == NULL_TELEMENT);
		it1.urmator();
		col++;
	}
	assert(col == m.nrColoane());

	m.modifica(1, 0, 10);
	m.modifica(1, 3, 20);

	IteratorMatrice it2 = m.iterator(1);
	it2.prim();

	int valori[4] = {10, 6, 0, 20};
	int i = 0;

	while (it2.valid()) {
		assert(it2.element() == valori[i]);
		it2.urmator();
		i++;
	}
	assert(i == 4);
	try {
		auto fail = m.iterator(-1);
		assert(false);
	} catch (...) {
		assert(true);
	}
}
