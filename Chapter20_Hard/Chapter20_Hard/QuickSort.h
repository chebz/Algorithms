#include <vector>

#pragma once
//need dynamic arrays!!!

typedef std::vector<int> vector;

int partition(vector &arr, vector &arrL, vector &arrR)
{
	int pivot = arr.back();
	arr.pop_back();

	while (!arr.empty())
	{
		int element = arr.back();
		arr.pop_back();

		if (element < pivot)
			arrL.push_back(element);
		else
			arrR.push_back(element);
	}

	return pivot;
}

void quicksort(vector &arr)
{
	if (arr.empty())
		return;

	vector arrL; 
	vector arrR;
	int pivot = partition(arr, arrL, arrR);

	quicksort(arrL);
	quicksort(arrR);
	arr.reserve(arrL.size() + arrR.size() + 1);
	arr.insert(arr.end(), arrL.begin(), arrL.end());
	arr.insert(arr.end(), pivot);
	arr.insert(arr.end(), arrR.begin(), arrR.end());
}



