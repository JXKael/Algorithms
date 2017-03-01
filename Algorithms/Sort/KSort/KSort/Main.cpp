#include <cstdlib>
#include <ctime>
#include "KSort.h"
using namespace std;

bool isDuplicate(int *, int, int);

void main()
{
	const int count = 10000;
	int a[count];
	srand((int)time(0));
	for (int i = 0; i < count; ++i)
	{
		int temp = rand() % (2 *count) + 1;
		// ---±ÜÃâÖØ¸´
		/*bool isDuplicate = false;
		for (int j = 0; j < i; ++j)
		{
			if (a[j] == temp)
			{
				isDuplicate = true;
				break;;
			}
		}
		*/
		if (isDuplicate(a, temp, i))
		{
			--i;
			continue;
		}

		a[i] = temp;
	}
	
	KSort ksort;
	ksort.sort(a, count, selection, false);
	// ksort.sort(a, count, insertion, false);
	// ksort.sort(a, count, shell, false);
	// ksort.sort(a, count, merge, false);
	// ksort.sort(a, count, mergeBU, false);
	// ksort.sort(a, count, quick, false);
	// ksort.sort(a, count, quick3way);

	system("pause");
}

bool isDuplicate(int *a, int temp, int i)
{
	bool isDuplicate = false;
	for (int j = 0; j < i; ++j)
	{
		if (a[j] == temp)
		{
			isDuplicate = true;
			break;
		}
	}
	return isDuplicate;
}