#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
	int result = 0;
	for (int i = 0; i < n; ++i) {
		result ^= A[i];
	}
	return result;
}

void testSingleNumber()
{
	int O[3] = { 1, 0, 1 };
	int n = singleNumber(O, 3);
	cout << n << endl;

	int A[5] = { 1, 3, 1, -1, 3 };
	n = singleNumber(A, 5);
	cout << n << endl;
		
	int B[3] = { -1, -1, -2 };
	n = singleNumber(B, 3);
	cout << n << endl;
}