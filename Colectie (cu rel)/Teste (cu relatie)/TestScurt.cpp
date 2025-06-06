#include "TestScurt.h"

#include <assert.h>

#include "Colectie.h"
#include "IteratorColectie.h"

void testAll() {
	Colectie c;
	c.adauga(5);
	c.adauga(6);
	c.adauga(0);
	c.adauga(5);
	c.adauga(10);
	c.adauga(8);

	assert(c.dim() == 6);
	assert(c.nrAparitii(5) == 2);

	assert(c.sterge(5) == true);
	assert(c.dim() == 5);

	assert(c.cauta(6) == true);
	assert(c.vida() == false);

	IteratorColectie ic = c.iterator();
	assert(ic.valid() == true);
	while (ic.valid()) {
		ic.element();
		ic.urmator();
	}
	assert(ic.valid() == false);
	ic.prim();
	assert(ic.valid() == true);

	// 🔍 Test pentru eliminaToateAparitiile
	c.adauga(6);
	c.adauga(6);
	assert(c.nrAparitii(6) == 3);

	int sterse = c.eliminaToateAparitiile(6);
	assert(sterse == 3);
	assert(c.nrAparitii(6) == 0);
}
