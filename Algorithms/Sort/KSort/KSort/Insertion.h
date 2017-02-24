#ifndef INSERTION_H
#define INSERTION_H

#include "Basic.h"

class Insertion : public Basic
{
public:
	Insertion() : Basic(){ sortType = insertion; }
	Insertion(int count) : Basic(count){ sortType = insertion; }
	Insertion(int *a, int count) : Basic(a, count){ sortType = insertion; }

public:
	void sort();
};

#endif // ! INSERTION_H