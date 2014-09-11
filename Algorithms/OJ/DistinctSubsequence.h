#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		if (T.size() == 0) return 1;

		int count = 0;

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == T[0]) {
				count += numDistinct(S.substr(i + 1, S.size() - i - 1), T.substr(1, T.size() - 1));
			}
		}

		return count;
	}

	void test() {
		string S = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
		string T = "bddabdcae";
		int n = numDistinct(S, T);
		cout << n;
	}
};