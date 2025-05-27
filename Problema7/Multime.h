#pragma once

typedef int TElem;
typedef bool(*Relatie)(TElem, TElem);

bool rel(TElem a, TElem b);
struct Nod {
	TElem e;
	int st; // left child index
	int dr; // right child index
};
class IteratorMultime;

class Multime {
	friend class IteratorMultime;

private:


	Nod* noduri;
	int capacitate;
	int radacina;
	int primLiber;
	int dimensiune;

	void resize();
	int creeazaNod(TElem e);

public:
	Multime();
	bool adauga(TElem e);
	bool sterge(TElem e);
	bool cauta(TElem elem) const;
	int dim() const;
	bool vida() const;
	IteratorMultime iterator() const;
	~Multime();
};