#pragma once

int addNumbers(int a, int b)
{
	if (b == 0)
		return a;

	int noCarryOver = a ^ b;
	int carryOver = (a & b) << 1;

	return addNumbers(noCarryOver, carryOver);
}