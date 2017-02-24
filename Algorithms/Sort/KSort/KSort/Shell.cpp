#include <iostream>
#include "Shell.h"
using namespace std;

//void Shell::sort()
//{
//	if (isNull())
//	{
//		cout << "The array is null";
//		return;
//	}
//
//	int h = 1;
//	while (h < count / 3) h = 3 * h + 1;
//
//	while (h >= 1)
//	{
//		for (int i = 0; i < count; ++i)
//		{
//			for (int j = i; j >= h && less(a[j], a[j - h]); j -= h)
//				exch(j, j - h);
//		}
//		h = h / 3;
//	}
//}

void Shell::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	int h = 1;
	while (h < count / 3) h = 3 * h + 1;

	while (h >= 1)
	{
		for (int i = 0; i < count; ++i)
		{
			int temp = a[i];
			int j = i;
			for (; j >= h && less(temp, a[j - h]); j -= h)
				a[j] = a[j - h];
			a[j] = temp;
		}
		h = h / 3;
	}
}