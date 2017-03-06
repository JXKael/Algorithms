#include <iostream>
#include "BinaryST.h"
#include "TestClass.h"
using namespace std;

int main()
{
	BinaryST<TestClass, int> BST;
	TestClass *test1 = new TestClass(1);
	TestClass *test2 = new TestClass(2);
	TestClass *test3 = new TestClass(3);
	TestClass *test4 = new TestClass(4);
	TestClass *test5 = new TestClass(5);
	TestClass *test6 = new TestClass(6);
	TestClass *test7 = new TestClass(7);

	BST.put(test1, test1->index);
	BST.put(test6, test6->index);
	//BST.put(*test4, test4->index);
	//BST.put(*test2, test2->index);
	//BST.put(*test7, test7->index);
	//BST.put(*test3, test3->index);
	//BST.put(*test5, test5->index);

	/*delete test1;
	delete test2;
	delete test3;
	delete test4;
	delete test5;*/
	delete test6;
	delete test7;
	int index = BST.get(new TestClass(6));
	if (NULL == index)
		cout << "get failed!" << endl;
	else
		cout << index << endl;

	// system("pause");
	char a;
	cin >> a;
}