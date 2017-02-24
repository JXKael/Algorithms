#include <iostream>
#include "Selection.h"
using namespace std;

void Selection::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	for (int i = 0; i < count; ++i)
	{
		int min = i;
		for (int j = i + 1; j < count; ++j)
			if (less(a[j], a[min]))
				min = j;
		exch(i, min);
	}
}