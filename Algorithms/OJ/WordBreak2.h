#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool checkLetters(string s, unordered_set<string> &dict)
{
	string words = "";
	for (string word : dict) words += word;
	for (char c : s) { if (words.find(c) == string::npos) return false; }
	return true;
}

void wordBreak(string s, unordered_set<string> &dict, vector<string> &result) {
	string ss = "";

	while (s.size() > 0) {
		ss += s.front();
		s.erase(0, 1);

		if (dict.find(ss) != dict.end()) {
			if (s.size() == 0)
				result.push_back(ss);
			else {
				vector<string> subResult;
				wordBreak(s, dict, subResult);
				for (string r : subResult) 
					result.push_back(ss + " " + r);
			}
		}
	}
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
	vector<string> result;
	if (s.size() == 0) return result;
	if (!checkLetters(s, dict)) return result;
	wordBreak(s, dict, result);
	return result;
}

void testWordBreak()
{
	unordered_set<string> dict = { "a", "abc", "b", "cd" };
	string s = "abcd";
	vector<string> result = wordBreak(s, dict);
	for (string s : result)
	{
		cout << s << endl;
	}
}