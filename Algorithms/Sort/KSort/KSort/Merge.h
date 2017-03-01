#ifndef MERGE_H
#define MERGE_H

#include "Basic.h"

class Merge : public Basic
{
private:
	int *aux;
public:
	Merge() : Basic(){ sortType = merge; }
	Merge(int count) : Basic(count){ sortType = merge; }
	Merge(int *a, int count) : Basic(a, count){ sortType = merge; }

public:
	void sort();

private:
	void sort(int lo, int hi);
	void funcMerge(int lo, int mid, int hi);
};

#endif // ! MERGE_H