#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool verifyLetters(string s, unordered_set<string> &dict)
{
	string words = "";

	for (string w : dict)
	{
		words += w;
	}

	for (char c : s)
	{
		if (words.find(c) == string::npos)
			return false;
	}
	return true;
}

bool wordBreak(string s, unordered_set<string> &dict) {

	if (s.length() == 0)
		return true;

	if (!verifyLetters(s, dict))
		return false;

	string ss = "";

	while (s.length() > 0)
	{
		if (dict.find(s) != dict.end() && wordBreak(ss, dict))
			return true;

		ss.insert(0, 1, s.back());
		s.erase(s.length() - 1, 1);
	}

	return false;
}

void testWordBreak()
{
	unordered_set<string> dict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	bool w = wordBreak(s, dict);
	cout<<w;
}