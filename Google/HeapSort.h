#include <iostream>
using namespace std;

/*
				0
			1		2
		3		45		6
	7		89	10111213	14
15		16

childL = i*2+1
childR = i*2+2
parent = floor(i-1)/2
*/
#pragma once

int parent(int i)
{
	return (i - 1) / 2;
}

int childL(int i)
{
	return i * 2 + 1;
}

int childR(int i)
{
	return i * 2 + 2;
}

void swap(int * arr, int a, int b)
{
	arr[a] ^= arr[b];
	arr[b] ^= arr[a];
	arr[a] ^= arr[b];
}

void siftDown(int * arr, int start, int end)
{
	int root = start;

	while (childL(root) <= end)
	{
		int child = childL(root);
		int tmp = root;
		
		//left child is greater than parent
		if (arr[tmp] < arr[child])
			tmp = child;

		//right child is greater than left
		if (child + 1 <= end && arr[tmp] < arr[child + 1])
			tmp = child + 1;

		if (tmp != root)
		{
			swap(arr, root, tmp);
			root = tmp;
		}
		else
		{
			return;
		}
	}
}

void heapify(int * arr, int length)
{
	int start = parent(length - 1);

	while (start >= 0)
	{
		siftDown(arr, start, length - 1);
		start--;
	}
}

void heapSort(int * arr, int length)
{
	heapify(arr, length);

	int end = length - 1;
	while (end > 0)
	{
		swap(arr, end, 0);
		end--;
		siftDown(arr, 0, end);
	}
}

void heapSortTest()
{
	int * arr = new int[10] { 5, 3, 9, 0, 7, 2, 4, 1, 6, 8 };
	heapSort(arr, 10);
	for (int i = 0; i < 9; ++i)
		cout << arr[i] << ", ";
	cout << arr[9] << endl;
	delete[] arr;
}