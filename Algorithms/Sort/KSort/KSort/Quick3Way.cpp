#include <iostream>
#include "Quick3Way.h"
using namespace std;

void Quick3Way::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	sort(0, count - 1);
}

void Quick3Way::sort(int lo, int hi)
{
	if (hi <= lo) return;

	int lt = lo, i = lo + 1, gt = hi;
	int c = a[lo];
	while (i <= gt)
	{
		if (a[i] < c) exch(lt++, i++);
		else if (a[i] > c) exch(i, gt--);
		else ++i;
	}

	sort(lo, lt - 1);
	sort(gt + 1, hi);
}