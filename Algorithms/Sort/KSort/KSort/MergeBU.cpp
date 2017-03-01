#include <iostream>
#include "MergeBU.h"
using namespace std;

// �Ե����ϵĹ鲢����
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
		if (i > mid)				   a[k] = aux[j++]; // i���������ߣ�ֻ��j��ֵ
		else if (j > hi)			   a[k] = aux[i++]; // j��������ߣ�ֻ��i��ֵ
		else if (less(aux[i], aux[j])) a[k] = aux[i++]; // i < j, ��ֵi
		else						   a[k] = aux[j++]; // i >= j, ��ֵj
	}
}