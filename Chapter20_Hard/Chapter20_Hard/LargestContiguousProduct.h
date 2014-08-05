

#pragma once
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x > y ? x : y; }

int largestProduct(int * values, int length)
{
	int min_ending_here = 1;
	int max_ending_here = 1;
	int max_so_far = 1;

	for (int i = 0; i < length; i++)
	{
		if (values[i] == 0)
		{
			min_ending_here = 1;
			max_ending_here = 1;
		}
		else if (values[i] > 0)
		{
			max_ending_here = values[i] * max_ending_here;
			min_ending_here = min(min_ending_here * values[i], 1);
		}
		else
		{
			int tmp = max_ending_here;
			max_ending_here = max(min_ending_here * values[i], 1);
			min_ending_here = values[i] * tmp;
		}

		if (max_ending_here > 1)
			max_so_far = max_ending_here;
	}

	return max_so_far;
}