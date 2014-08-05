#include <string>
#pragma once

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int largestDistance(string& str)
{
	int maxDist = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		int sum_so_far = 0;

		for (int n = i; n < str.size(); ++n)
		{
			if (str[n] == '*')
				++sum_so_far;
			else
				--sum_so_far;

			if (sum_so_far == 0)
				maxDist = max(maxDist, n - i);					
		}

		if (maxDist >= str.size() - i)
			break;
	}

	return maxDist;
}