#include <iostream>
#include "MergeBU.h"
using namespace std;

// 自底向上的归并排序
void MergeBU::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	if (nullptr != aux)
		delete aux;
	aux = new int[count];

	for (int sz = 1; sz < count; sz = sz + sz)
		for (int lo = 0; lo < count - sz; lo += sz + sz)
			funcMerge(lo, lo + sz - 1, _min_(lo + sz + sz - 1, count - 1));

	delete aux;
}

void MergeBU::funcMerge(int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; ++k)
		aux[k] = a[k];

	for (int k = lo; k <= hi; ++k)
	{
		if (i > mid)				   a[k] = aux[j++]; // i超过了中线，只用j赋值
		else if (j > hi)			   a[k] = aux[i++]; // j超过了最高，只用i赋值
		else if (less(aux[i], aux[j])) a[k] = aux[i++]; // i < j, 赋值i
		else						   a[k] = aux[j++]; // i >= j, 赋值j
	}
}