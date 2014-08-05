#include <climits>
#include <math.h>
#pragma once

int shortestDistance(char *str, char a, char b)
{
	if (a == b)
		return 0;

	int distance = INT_MAX;
	int pA = -1, pB = -1;
	int i = 0;

	while (str && *str)
	{
		if (*str == a)
			pA = i;
		else if (*str == b)
			pB = i;

		if (abs(pA - pB) < distance && pA != -1 && pB != -1)
			distance = abs(pA - pB);

		++i;
		++str;
	}

	return distance;
}