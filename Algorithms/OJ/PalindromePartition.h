#include <string>
#include <vector>
using namespace std;
#pragma once

class Solution {
public:
	typedef vector<vector<string>> Pseq;
	
	vector<string> join(vector<string> v1, vector<string> v2) {
		v1.insert(v1.end(), v2.begin(), v2.end());
		return v1;
	}

	Pseq join(Pseq &p1, Pseq &p2) {
		Pseq result;
		for (vector<string> &v1 : p1)
		{
			for (vector<string> &v2 : p2)
			{
				vector<string> v = join(v1, v2);
				result.push_back(v);
			}
		}
		return result;
	}

	bool isPalindrome(string &s) {
		if (s.size() == 0) return false;

		auto itStart = s.begin();
		auto itEnd = s.end() - 1;
		while (itStart < itEnd) {
			if (*itStart != *itEnd)
				return false;
			itStart++;
			itEnd--;
		}
		return true;
	}

	vector<vector<string>> partition(string s) {
		if (s.size() == 0) return{};
		if (s.size() == 1) return{ { s } };

		Pseq palindromes;

		for (int i = 0; i < s.size(); ++i) {
			string ss = s.substr(0, i + 1);
			if (isPalindrome(ss))
			{
				Pseq pL = { { ss } };
				Pseq result;
				if (i < s.size() - 1) {
					Pseq pR = partition(s.substr(i + 1, s.size() - i - 1));
					result = join(pL, pR);
				}
				else result = pL;
				palindromes.insert(palindromes.end(), result.begin(), result.end());
			}
		}

		return palindromes;
	}

	int minCut(string s) {
		Pseq p = partition(s);
		if (p.size() == 0) return 0;
		int min = p[0].size();
		for (vector<string> v : p) {
			if (min > v.size())
				min = v.size();
		}

		return min - 1;
	}

	void test() {
		string s = "ababababababababababababcbabababababababababababa";
		Pseq p = partition(s);

		for (auto v : p) {
			for (string s : v)
			{
				cout << s << ", ";
			}
			cout << endl;
		}

		int min = minCut(s);
		cout << min << endl;
	}
};