#include <iostream>
using namespace std;
#pragma once

int singleNumber(int A[], int n) {
	int ones = 0, twos = 0;
	for (int i = 0; i < n; i++){
		ones = (ones ^ A[i]) & ~twos;
		twos = (twos ^ A[i]) & ~ones;
	}
	return ones;
}

void testSingleNumber()
{
	int A[3] = { 3, 3, 1 };
	int n = singleNumber(A, 3);
	cout << n << endl;
}