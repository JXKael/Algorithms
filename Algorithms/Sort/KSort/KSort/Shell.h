#ifndef SHELL_H
#define SHELL_H

#include "Basic.h"

class Shell : public Basic
{
public:
	Shell() : Basic(){ sortType = shell; }
	Shell(int count) : Basic(count){ sortType = shell; }
	Shell(int *a, int count) : Basic(a, count){ sortType = shell; }

public:
	void sort();
};

#endif // ! INSERTION_H