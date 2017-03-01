#include <iostream>
#include <ctime>
#include "KSort.h"
using namespace std;

void KSort::sort(int *a, int count, ESortType sortType, bool isShow)
{
	clock_t start, end;
	double duration;
	Basic *method = nullptr;

	switch (sortType)
	{
	case selection: method = new Selection(a, count); break;
	case insertion: method = new Insertion(a, count); break;
	case shell: method = new Shell(a, count); break;
	case merge: method = new Merge(a, count); break;
	case mergeBU: method = new MergeBU(a, count); break;
	case quick: method = new Quick(a, count); break;
	case quick3way: method = new Quick3Way(a, count); break;
	default:
		break;
	}
	if (nullptr == method)
	{
		cout << "方法实例化出错！" << endl;
		return;
	}
	// record start time
	start = clock();
	method->sort();
	// record end time
	end = clock();
	duration = (double)(end - start);

	if (method->isSorted())
	{
		if (isShow)
			method->show();

		cout << endl << endl << SortType::NameSortType(method->SortType()) << " Sort: " << method->Count() << " element sorted, used " << duration << "ms" << endl << endl;
	}
	else
	{
		cout << "排序未成功" << endl;
	}

	delete method;
}