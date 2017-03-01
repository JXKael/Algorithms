#ifndef MERGE_BU_H
#define MERGE_BU_H

#include "Basic.h"

class MergeBU : public Basic
{
private:
	int *aux;
public:
	MergeBU() : Basic(){ sortType = mergeBU; }
	MergeBU(int count) : Basic(count){ sortType = mergeBU; }
	MergeBU(int *a, int count) : Basic(a, count){ sortType = mergeBU; }

public:
	void sort();

private:
	// void sort(int lo, int hi); ²»ÐèÒªµÝ¹é
	void funcMerge(int lo, int mid, int hi);
};

#endif // ! MERGE_BU_H