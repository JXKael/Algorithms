#include <iostream>
#include "Insertion.h"
using namespace std;

//void Insertion::sort()
//{
//	if (isNull())
//	{
//		cout << "The array is null";
//		return;
//	}
//
//	for (int i = 1; i < count; ++i)
//	{
//		for (int j = i; j > 0 && less(a[j], a[j - 1]); --j)
//			exch(j, j-1);
//	}
//}

// 优化的插入排序
void Insertion::sort()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	for (int i = 1; i < count; ++i)
	{
		int temp = a[i];
		int j = i;
		for (; j > 0 && less(temp, a[j - 1]); --j)
			a[j] = a[j - 1];
		a[j] = temp;
	}
}