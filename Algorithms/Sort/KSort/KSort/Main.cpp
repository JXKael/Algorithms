#include <cstdlib>
#include <ctime>
#include "KSort.h"
using namespace std;

void main()
{
	const int count = 2000;
	int a[count];
	srand((int)time(0));
	for (int i = 0; i < count; ++i)
	{
		int temp = rand() % (2 *count) + 1;
		bool isDuplicate = false;
		for (int j = 0; j < i; ++j)
		{
			if (a[j] == temp)
			{
				isDuplicate = true;
				break;;
			}
		}

		if (isDuplicate)
		{
			--i;
			continue;
		}

		a[i] = temp;
	}
	
	KSort ksort;
	// ksort.sort(a, count, selection);
	// ksort.sort(a, count, insertion);
	ksort.sort(a, count, shell);

	system("pause");
}