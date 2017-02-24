#ifndef SELECTION_H
#define SELECTION_H

#include "Basic.h"

class Selection : public Basic
{
public:
	Selection() : Basic(){ sortType = selection; }
	Selection(int count) : Basic(count){ sortType = selection; }
	Selection(int *a, int count) : Basic(a, count){ sortType = selection; }

public:
	void sort();
};

#endif // ! SELECTION_H