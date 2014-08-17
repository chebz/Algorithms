#include <iostream>
using namespace std;

#pragma once

int pow(int a, int b)
{
	if (a == 0)
		return 0;

	if (b == 0)
		return 1;

	int half = pow(a, b / 2);

	return half*half*(b % 2 == 0 ? 1 : a);
}

void powTest()
{
	cout << pow(3, 3) << endl;
}