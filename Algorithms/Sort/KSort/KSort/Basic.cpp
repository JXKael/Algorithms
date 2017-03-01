#include <iostream>
#include "Basic.h"
using namespace std;

Basic::Basic()
{
	count = 0;
	a = nullptr;
}
Basic::Basic(int count)
{
	if (0 == count)
		return;

	a = new int[count];
	this->count = count;
}
Basic::Basic(int *a, int count)
{
	if (0 == count)
		return;

	if (this->a != nullptr)
		delete this->a;

	this->a = new int[count];
	this->count = count;
	for (int i = 0; i < this->count; ++i)
	{
		this->a[i] = a[i];
	}
}

bool Basic::isSorted()
{
	for (int i = 1; i < count; ++i)
		if (less(a[i], a[i - 1])) return false;
	return true;
}

void Basic::show()
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	for (int i = 0; i < count; ++i)
	{
		cout << a[i];
		if (i != count - 1)
			cout << ' ';
	}
	cout << endl;
}

void Basic::exch(int i, int j)
{
	if (isNull())
	{
		cout << "The array is null";
		return;
	}

	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}