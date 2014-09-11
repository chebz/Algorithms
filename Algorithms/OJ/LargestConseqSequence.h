#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#pragma once

class Solution {
public:
	int longestConsecutive(vector<int> &num) {

		unordered_map<int, int> seq;
		unordered_map<int, int> seqStart;
		int max = 0;

		for (int n : num) {
			if (!seq.count(n)) {
				int c = 1;
				seqStart[n] = n;

				if (seqStart.count(n - 1)) {
					seqStart[n - 1] = seqStart[seqStart[n - 1]];
					seqStart[n] = seqStart[n - 1];
					c += seq[seqStart[n]];
				}
				if (seqStart.count(n + 1)) {
					seqStart[n + 1] = seqStart[n];
					c += seq[n+1];
				}				
				seq[seqStart[n]] = c;
				seq[n] = c;
				if (c > max) max = c;

			}
		}
		return max;
	}

	void test() {
		//vector<int> v = { 4, 0, -4, -2, 2, 5, 2, 0, -8, -8, -8, -8, -1, 7, 4, 5, 5, -4, 6, 6, -3 };
		//vector<int> v = { 0, -1 };
		vector<int> v = { -6, -9, 8, -8, -1, -3, -6, 8, -9, -1, -4, -8, -5, 0, 1, 6, -8, -5, -7, 8, -2, -8, 4, 5, -5, -1, -5 };
		int n = longestConsecutive(v);
		cout << n << endl;
	}
};
