#include "MergeSortWithIterator.h"
#include <iomanip>
using namespace std;
#pragma once;

typedef vector<int>::iterator it;

bool isLocalMin(vector<int> &arr, it a)
{
	return ((a == arr.begin() || *a <= *(a - 1)) && (a + 1 == arr.end() || *a <= *(a + 1)));
}

bool isLocalMax(vector<int> &arr, it a)
{
	return ((a == arr.begin() || *a >= *(a - 1)) && (a + 1 == arr.end() || *a > *(a + 1)));
}

int findNextLocalMin(vector<int> &arr, it a)
{
	int n = 0;
	while (a != arr.end() && !isLocalMin(arr, a)) {
		n++;
		a++;
	}
	return n;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int candy(vector<int> &ratings) {
	int candyAdded = 0;
	int candyCount = 0;

	for (int i : ratings) cout << setw(4) << i;
	cout << endl;

	for (it a = ratings.begin(); a < ratings.end(); a++)
	{
		if (isLocalMin(ratings, a)) candyAdded = 1;
		else if (a == ratings.begin() || *a > *(a - 1)) candyAdded++;
		else candyAdded = max(1, candyAdded - 1);

		int next = candyAdded;	
		if (isLocalMax(ratings, a)) {
			next = findNextLocalMin(ratings, a) + 1;
			if (next > candyAdded) {
				candyAdded = next;
			}
		}
	
		candyCount += candyAdded;
		cout << setw(4) << candyAdded;

		candyAdded = next;
	}

	return candyCount;
}

void testCandy()
{
	vector<int> ratings = { 58, 21, 72, 77, 48, 9, 38, 71, 68, 77, 82, 47, 25, 94, 89, 54, 26, 54, 54, 99, 64, 71, 76, 63, 81, 82, 60, 64, 29, 51, 87, 87, 72, 12, 16, 20, 21, 54, 43, 41, 83, 77, 41, 61, 72, 82, 15, 50, 36, 69, 49, 53, 92, 77, 16, 73, 12, 28, 37, 41, 79, 25, 80, 3, 37, 48, 23, 10, 55, 19, 51, 38, 96, 92, 99, 68, 75, 14, 18, 63, 35, 19, 68, 28, 49, 36, 53, 61, 64, 91, 2, 43, 68, 34, 46, 57, 82, 22, 67, 89 };
	int n = candy(ratings);
}