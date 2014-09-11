#include <string>
#include <vector>
#include <iostream>
using namespace std;
#pragma once

class Solution {
public:

	int minCut(string s) {
		int n = s.size();
		if (n < 2) return 0;

		vector<vector<bool>> pal(n, vector<bool>(n, false));
		vector<int> d(n, 0);

		for (int i = 0; i < n; ++i) {
			d[i] = i;
			for (int j = i; j >= 0; --j) {				
				if (s[i] == s[j] && (i - j < 2 || pal[j + 1][i - 1])) {
					pal[j][i] = true;

					if (j == 0)
						d[i] = 0;
					else {
						if (d[j - 1] + 1 < d[i])
							d[i] = d[j - 1] + 1;
					}
				}
			}
		}

		return d[n - 1];
	}

	void test() {
		string s = "cdd";
		int min = minCut(s);
		cout << min << endl;
	}
};