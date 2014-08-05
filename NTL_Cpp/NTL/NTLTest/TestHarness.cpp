#include "TestHarness.h"

#include <iostream>
#include <stdlib.h>

TestHarness::TestHarness()
{
}


TestHarness::~TestHarness()
{
}

void TestHarness::timerStart()
{
	oStartTime = clock();
}

void TestHarness::timerEnd(const std::string& output)
{
	clock_t oEndTime = clock();
	double fElapsedTime = (double)(oEndTime - oStartTime) / CLOCKS_PER_SEC;
	std::cout << output << fElapsedTime << std::endl;
}

void TestHarness::runTests()
{
	test_swap();
	test_linkedList();
}


void TestHarness::test_swap()
{
	std::cout << "Testing swap" << std::endl;
	clock_t oStartTime = clock();
	int a = 1;
	int b = 2;
	ntl::swap<int>(a, b);

	char *p_a = "aaa";
	char *p_b = "bbb";
	ntl::swap(p_a, p_b);

	clock_t oEndTime = clock();
	double fElapsedTime = (double)(oEndTime - oStartTime) / CLOCKS_PER_SEC;
	std::cout << "Testing swap success: " << fElapsedTime << "s" << std::endl;
}

void TestHarness::test_linkedList()
{
	std::cout << "Testing LinkedList" << std::endl;
	int nSeed = 0;
	srand(nSeed);

	clock_t oStartTime = clock();

	LinkedList<int> list;
	for (int i = 0; i < 2000000; ++i)
	{
		list.add(rand());
	}
	
	LinkedList<int> list2;
	list2 = list;

	/*
	auto iter = list.begin();
	list.remove(iter);

	std::cout << list.getSize() << "\n";
	std::cout << list2.getSize() << "\n";*/

	clock_t oEndTime = clock();
	double fElapsedTime = (double)(oEndTime - oStartTime) / CLOCKS_PER_SEC;
	std::cout << "Testing LinkedList success: " << fElapsedTime << "s" << std::endl;
}