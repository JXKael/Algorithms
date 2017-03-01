#include <iostream>
#include "Merge.h"
using namespace std;

void Merge::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	if (nullptr != aux)
		delete aux;
	aux = new int[count];

	sort(0, count - 1);

	delete aux;
}

// �Զ����µĹ鲢����
void Merge::sort(int lo, int hi)
{
	if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
	sort(lo, mid);
	sort(mid + 1, hi);
	funcMerge(lo, mid, hi);
}

void Merge::funcMerge(int lo, int mid, int hi)
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