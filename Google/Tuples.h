#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#pragma once

/*
level 1 = 3 unique: {1,2,3} = 1 tuple
level 2 = 4 unique: {1,2,3} {1,2,4} + {1,3,4} + 1 = 3 + 1 = 4 tuples
level 3 = 5 unique: {1,2,3} {1,2,4} {1,2,5} + {1,3,4} {1,3,5} + {1,4,5} + 4 = 10 tuples
level 4 = 6 unique: {1,2,3} {1,2,4} {1,2,5} {1,2,6} + {1,3,4} {1,3,5} {1,3,6} {1,4,5} {1,4,6} {1,5,6} + 10 = 20
*/

typedef vector<int> Triplet;

int getSumSequence(int n)
{
	if (n <= 0)
		return 0;

	return n + getSumSequence(n - 1);
}

int countTriplets(int index, int unique)
{
	int level = unique - index  - 2;

	if (level < 1)
		return 0;

	if (level == 1)
		return 1;

	return getSumSequence(level);
}

//BFS approach
void countTriplets(const int * arr, int length, vector<Triplet*>& triplets)
{
	//first count number of unique elements to avoid duplicates
	int unique = 1;
	for (int i = 1; i < length; ++i)
	{
		if (arr[i - 1] != arr[i])
			unique++;
	}

	deque<Triplet*> constructed;
	
	int nConstructed = countTriplets(0, unique);
	int elementID = 0;

	for (int i = 0; i < length; ++i)
	{
		//skip doubles
		if (i > 0 && arr[i - 1] == arr[i])
			continue;		

		//Add new tuples to deque on this level
		int nTriplets = countTriplets(elementID++, unique);
		for (int t = 0; t < nTriplets; ++t)
		{
			Triplet *triplet = new Triplet();
			constructed.push_front(triplet);
		}

		//Process existing tuples in deque by adding arr[i] to the first nConstructed elements
		//if tuple has 3 elements pop it and add it to result
		for (int t = 0; t < nConstructed; ++t)
		{
			Triplet *first = constructed.front();

			first->push_back(arr[i]);
			if (first->size() == 3)
			{
				triplets.push_back(first); //if triplet is completed add it to triplets
			}
			else
			{
				constructed.push_back(first); //otherwise keep it in constructed
			}
			constructed.pop_front();
		}
	}
}

void testCountTuples()
{
	int * arr = new int[7] { 1, 1, 2, 2, 3, 4, 5 };
	vector<Triplet*> triplets;
	countTriplets(arr, 7, triplets);

	for (auto triplet : triplets)
	{
		cout << "{ ";
		for (int i : *triplet)
		{
			cout << i << " ";
		}
		cout << "} ";

		delete triplet;
	}
}