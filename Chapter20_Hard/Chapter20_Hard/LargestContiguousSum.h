#pragma once

int largestSum(int * values, int length)
{
	if (!values)
		return 0;

	int largestSum = 0;
	int currentSum = 0;

	for (int i = 0; i < length; i++)
	{
		currentSum += values[i];

		if (currentSum < 0)
			currentSum = 0;

		if (currentSum > largestSum)
			largestSum = currentSum;
	}

	return largestSum;
}