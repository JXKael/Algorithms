#ifndef E_SORT_TYPE_H
#define E_SORT_TYPE_H

enum ESortType
{
	selection,
	insertion,
	shell,
	merge,
	mergeBU,
	quick,
	quick3way
};

class SortType
{
public:
	static char* NameSortType(ESortType sortType)
	{
		switch (sortType)
		{
		case selection: return "Selection";
		case insertion: return "Insertion";
		case shell: return "Shell";
		case merge: return "Merge";
		case mergeBU: return "MergeBU";
		case quick: return "Quick";
		case quick3way: return "Quick 3Way";
		default: return "null name";
		}
	}
};

#endif // ! E_SORT_TYPE_H