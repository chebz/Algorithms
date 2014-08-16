#include <iostream>
using namespace std;

#pragma once

template <class T>
class HeapSort
{
	static int parent(int i)
	{
		return (i - 1) / 2;
	}

	static int childL(int i)
	{
		return i * 2 + 1;
	}

	static int childR(int i)
	{
		return i * 2 + 2;
	}

	static void swap(T * arr, int a, int b)
	{
		T tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	static void siftDown(T * arr, int(*comparison)(T, T), int start, int end)
	{
		int root = start;

		while (childL(root) <= end)
		{
			int child = childL(root);
			int tmp = root;

			//left child is greater than parent
			if (comparison(arr[tmp], arr[child]) < 0)
				tmp = child;

			//right child is greater than left
			if (child + 1 <= end && comparison(arr[tmp], arr[child + 1]) < 0)
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

	static void heapify(T * arr, int(*comparison)(T, T), int length)
	{
		int start = parent(length - 1);

		while (start >= 0)
		{
			siftDown(arr, comparison, start, length - 1);
			start--;
		}
	}

public:
	static void sort(T * arr, int(*comparison)(T, T), int length)
	{
		heapify(arr, comparison, length);

		int end = length - 1;
		while (end > 0)
		{
			swap(arr, end, 0);
			end--;
			siftDown(arr, comparison, 0, end);
		}
	}
};

int comparisonInt(int a, int b)
{
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int comparisonCharDescending(char a, char b)
{
	if (a > b)
		return -1;
	if (a < b)
		return 1;
	return 0;
}

void heapSortTest()
{
	int * intArr = new int[10] { 5, 3, 9, 0, 7, 2, 4, 1, 6, 8 };
	HeapSort<int>::sort(intArr, &comparisonInt, 10);
	for (int i = 0; i < 9; ++i)
		cout << intArr[i] << ", ";
	cout << intArr[9] << endl;
	delete[] intArr;


	char * charArr = new char[6] { 'a', 's', 'z', 'f', 'r', 'y' };
	HeapSort<char>::sort(charArr, &comparisonCharDescending, 6);
	for (int i = 0; i < 5; ++i)
		cout << charArr[i] << ", ";
	cout << charArr[5] << endl;
	delete[] charArr;
}