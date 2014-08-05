#include <stdlib.h>
#include <time.h>

#pragma once

int * randomSubset(int *set, int setLength, int &subsetLength)
{	
	srand(time(NULL));
	subsetLength = rand() % (setLength - 1);
	int * subset = new int[subsetLength];

	for (int i = 0; i < subsetLength; ++i)
	{
		int index = rand() % (setLength - i) + i;
		subset[i] = set[index];
		if (index != i)
		{
			set[i] ^= set[index];
			set[index] ^= set[i];
			set[i] ^= set[index];
		}
	}

	return subset;
}