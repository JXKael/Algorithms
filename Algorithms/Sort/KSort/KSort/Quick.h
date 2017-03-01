#ifndef QUICK_H
#define QUICK_H

#include "Basic.h"

class Quick : public Basic
{
public:
	Quick() : Basic(){ sortType = quick; }
	Quick(int count) : Basic(count){ sortType = quick; }
	Quick(int *a, int count) : Basic(a, count){ sortType = quick; }

public:
	void sort();

private:
	void sort(int lo, int hi);
	int partition(int lo, int hi);
};

#endif // ! QUICK_H