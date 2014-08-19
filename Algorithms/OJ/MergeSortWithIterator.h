#include <iostream>
#include <vector>
using namespace std;

#pragma once;

typedef vector<int>::iterator it;

void swap(vector<int> &arr, it a, it b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

it merge(vector<int> &arr, it a, it mid, it b) {
	it center = mid;
	it first = a;
	it result = a;
	while (a < center || mid != b) {
		if (a < center && (mid == b || *a < *mid)) {
			if (a >= result) swap(arr, a, result++);
			a++;
		}
		else {
			if (mid >= result && *mid < *result) swap(arr, mid, result++); 
			mid++;			
		}
	}
	return first;
}

it split(vector<int> &arr, it a, it b) {
	if (a == b) return a;	

	it slow = a;
	it fast = a + 1;
	while (fast != b && fast + 1 < b) {
		slow++;
		fast += 2;
	}
	return slow + 1;
}

void mergeSort(vector<int> &arr, it a, it b) {
	if (a == b || a + 1 == b) return;

	it mid = split(arr, a, b);
	mergeSort(arr, a, mid);
	mergeSort(arr, mid, b);
	merge(arr, a, mid, b);
}

void testMergeSort()
{
	vector<int> arr = { 9, 2, 0, 1, 5, 3 };
	mergeSort(arr, arr.begin(), arr.end());

	for (int i : arr) cout << i << ", ";

}