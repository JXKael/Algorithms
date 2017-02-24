#include <iostream>
#include <ctime>
#include "KSort.h"
using namespace std;

void KSort::sort(int *a, int count, ESortType sortType)
{
	clock_t start, end;
	double duration;
	Basic *method = nullptr;

	switch (sortType)
	{
	case selection: method = new Selection(a, count); break;
	case insertion: method = new Insertion(a, count); break;
	case shell: method = new Shell(a, count); break;
	default:
		break;
	}

	// record start time
	start = clock();
	method->sort();
	// record end time
	end = clock();
	duration = (double)(end - start);

	if (method->isSorted())
		method->show();

	cout << endl << endl << method->SortType() << ": " << method->Count() << " element sorted, used " << duration << "ms" << endl;
}