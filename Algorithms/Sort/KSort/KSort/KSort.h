#ifndef KSORT_H
#define KSORT_H

#include "ESortType.h"
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"


class KSort
{
public:
	void sort(int *a, int count, ESortType sortType);
};

#endif // !KSORT_H