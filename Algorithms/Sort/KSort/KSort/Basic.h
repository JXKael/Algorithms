#ifndef BASIC_H
#define BASIC_H

#include "ESortType.h"

#define _min_(a,b) a < b? a: b

class Basic
{
protected:
	int *a;
	int count;
	ESortType sortType;

public:
	Basic();
	Basic(int count);
	Basic(int *a, int count);

public:
	virtual void sort() = 0;
	bool isSorted();
	void show();
	inline int Count(){ return count; }
	inline virtual ESortType SortType(){ return sortType; }

protected:
	inline bool isNull(){ return nullptr == a; }
	inline bool less(int v, int w){ return v < w; }
	void exch(int i, int j);
};

#endif // ! BASIC_H