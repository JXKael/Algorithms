#include <iostream>
#include "Quick.h"
using namespace std;

void Quick::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	sort(0, count - 1);
}

void Quick::sort(int lo, int hi)
{
	if (hi <= lo) return;
	int j = partition(lo, hi);
	sort(lo, j - 1);
	sort(j + 1, hi);
}

int Quick::partition(int lo, int hi)
{
	// 将数组切分为a[lo..i-1], a[i], a[i+1..hi]
	int i = lo, j = hi + 1;
	int v = a[lo];
	while (true)
	{
		while (less(a[++i], v)) if (i == hi) break;
		while (less(v, a[--j])) if (j == lo) break;
		if (i >= j) break;
		exch(i, j);
	}
	exch(lo, j);
	return j;
}