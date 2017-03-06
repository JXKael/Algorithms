#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include <iostream>
using namespace std;

class TestClass
{
public:
	int index;
	TestClass(int index) : index(index){}

public:
	const bool operator<(const TestClass& v) const { return this->index < v.index; }
	const bool operator>(const TestClass& v) const { return this->index > v.index; }
	const bool operator==(const TestClass& v) const { return this->index == v.index; }

	const bool operator<(const TestClass& v){ return this->index < v.index; }
	const bool operator>(const TestClass& v){ return this->index > v.index; }
	const bool operator==(const TestClass& v){ return this->index == v.index; }
};

ostream& operator<<(ostream &out, const TestClass& v)
{
	out << v.index << endl;
	return out;
}

#endif // ! TEST_CLASS_H