#include <vector>

#pragma once

using namespace std;

void findIntersection(vector<int>& a, vector<int>& b, vector<int>& c)
{
	a.sort(); // nlogn
	b.sort(); // nlogn

	auto it_a = a.begin();
	auto it_b = b.begin();
	int current = 0;

	while (it_a != a.end() && it_b != a.end()) // n
	{
		if (*it_a == *it_b)
		{
			c.push_back(*it_a);
			it_a++;
			it_b++;
			current = *it_a;
		}

		while ((*it_a > *it_b || *it_b == current) && it_b != b.end())
		{
			it_b++;
		}

		if (it_b == b.end())
		{
			break;
		}

		while ((*it_b > *it_a || *it_a == current) && it_a != a.end())
		{
			it_a++;
		}
	}
}