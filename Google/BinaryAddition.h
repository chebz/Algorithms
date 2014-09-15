#include <iostream>
using namespace std;

class Solution {
public:
	int addBits(int a, int b, int &c) {
		int output = a^b^c;
		c = ((a ^ b) & c) | (a & b);
		return output;
	}

	int addInts(int a, int b) {
		int c = 0;
		int output = 0;

		for (int i = 0; i < 32; ++i) {
			int mask = 1 << i;
			output += addBits(a & mask, b & mask, c);
			c <<= 1;
		}

		return output;
	}

	void test() {
		int n = addInts(53, 7);
		cout << n << endl;
	}
};