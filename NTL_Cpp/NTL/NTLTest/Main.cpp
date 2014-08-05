#include <iostream>
#include "NTL.h"
#include "TestHarness.h"

using namespace std;


void linkedListTest()
{
	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);

	LinkedList<int> list2;
	list2 = list;
	cout << list.getSize() << "\n";
	cout << list2.getSize() << "\n";

	auto iter = list.begin();
	list.remove(iter);

	cout << list.getSize() << "\n";
	cout << list2.getSize() << "\n";
}

void hashtableTest()
{
	Hashtable<int> table1(50);
	table1.insert("abc", 123);

	Hashtable<int> table2 = table1;

	cout << table1.getSize() << "\n";
	cout << table2.getSize() << "\n";
}


int main()
{
	//linkedListTest();

	TestHarness test;
	test.runTests();

	std::cin.ignore();
	return 0;
}