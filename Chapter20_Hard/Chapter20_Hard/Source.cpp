#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "AddNumbers.h"
#include "ShuffleCards.h"
#include "RandomSet.h"
#include "ShortestDistance.h"
#include "LargestContiguousSum.h"
#include "QuickSort.h"
#include "IntToStr.h"
#include "LargestContiguousProduct.h"

void AddNumbersTest()
{
	std::cout << "ADD NUMBERS TEST" << std::endl;
	int a = 37;
	int b = 1055;
	int result = addNumbers(a, b);
	std::cout << a << " + " << b << " = " << result << std::endl;
	std::cout << std::endl;
}

void ShuffleTest()
{
	std::cout << "SHUFFLE CARDS TEST" << std::endl;
	shuffleCards();
	std::cout << std::endl;
}

void RandomSetTest()
{
	std::cout << "RANDOM SUBSET TEST" << std::endl;
	int set[100];

	for (int i = 0; i < 100; ++i)
		set[i] = i;

	int subsetLength;
	int *subset = randomSubset(set, 100, subsetLength);

	for (int i = 0; i < subsetLength; ++i)
		std::cout << subset[i] << " ";

	delete[] subset;

	std::cout << std::endl;
}

void ShortestDistanceTest()
{
	std::cout << "SHORTEST DISTANCE TEST" << std::endl;
	
	char *sentence = "monkey likes bananas but doesn't like programming.";
	char a = 'i';
	char b = 'e';
	int dist = shortestDistance(sentence, a, b);
	std::cout << sentence << std::endl;
	std::cout << a << ", " << b << std::endl;
	std::cout << "distance: " << dist << std::endl;
	std::cout << std::endl;
}

void LargestContigSumTest()
{
	std::cout << "LARGEST CONTIGUOUS SUM TEST" << std::endl;
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int sum = largestSum(a, 8);
	std::cout << "sum: " << sum << std::endl;
	std::cout << std::endl;
}

void QuicksortTest()
{
	std::cout << "QUICKSORT TEST" << std::endl;

	srand(time(NULL));
	vector v;
	for (int i = 0; i < 10; ++i)
		v.push_back(rand() % 100);
	
	std::cout << "unsorted: " << std::endl;
	for (int i = 0; i < 10; ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	quicksort(v);

	std::cout << "sorted: " << std::endl;
	for (int i = 0; i < 10; ++i)
		std::cout << v[i] << " ";

	std::cout << std::endl;
}

void IntToStrTest()
{
	std::cout << "INT TO STR TEST" << std::endl;
	int i = -123;
	char c[100];
	convertIntToString(i, c);
	std::cout << c << std::endl;
	std::cout << std::endl;
}

void LargestContigProductTest()
{
	std::cout << "LARGEST CONTIGUOUS PRODUCT TEST" << std::endl;
	int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int p = largestProduct(arr, n);
	std::cout << p << std::endl;
	std::cout << std::endl;
}

int main()
{
	AddNumbersTest();
	ShuffleTest();
	RandomSetTest();
	ShortestDistanceTest();
	LargestContigSumTest();
	QuicksortTest();
	IntToStrTest();
	LargestContigProductTest();

	int n;
	std::cin >> n;
	return 0;
}
