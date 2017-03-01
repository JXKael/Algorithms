#ifndef KSORT_H
#define KSORT_H

#include "ESortType.h"

#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"
#include "Merge.h"
#include "MergeBU.h"
#include "Quick.h"
#include "Quick3Way.h"

class KSort
{
public:
	void sort(int *a, int count, ESortType sortType, bool isShow = true);
};

#endif // !KSORT_H