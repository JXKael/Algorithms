#ifndef QUICK_3_WAY_H
#define QUICK_3_WAY_H

#include "Basic.h"

class Quick3Way : public Basic
{
public:
	Quick3Way() : Basic(){ sortType = quick; }
	Quick3Way(int count) : Basic(count){ sortType = quick; }
	Quick3Way(int *a, int count) : Basic(a, count){ sortType = quick; }

public:
	void sort();

private:
	void sort(int lo, int hi);
};

#endif // ! QUICK_3_WAY_H