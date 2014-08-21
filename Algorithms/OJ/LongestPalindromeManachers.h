#include <string>
#pragma once
using namespace std;

struct  Solution
{
	//because palindromes can be odd and even number of characters
	//e.g. aba = center @b, whereas abba = center between bb
	//add artificial characters to represent centers of even-size palindromes
	//this simplifies solution
	void addBoundaries(string &s) {
		int n = s.size();
		for (int i = 0; i <= n; ++i) {
			s.insert(i * 2, "|");
		}
		//abc = |abc, |a|bc, |a|b|c, |a|b|c|
	}

	//clean the string
	void removeBoundaries(string &s) {
		int n = (s.size() - 1) / 2;
		for (int i = 0; i <= n; ++i) {
			s.erase(i, 1);
		}
		//|a|b|c|, a|b|c|, ab|c|, abc|, abc
	}

	string findLongestPalindrome(string s) {
		if (s.size() == 0) return "";		
		addBoundaries(s); //pre-process string

		int lengths[100] = { 0 }; // lengths array to track longest palindromes
		int center = 0; //center of the current longest palindrome
		int right = 0; //right-most edge of the current longest palindrome

		//this populates the lengths array, it starts at one because first character is '|'
		for (int i = 1; i < s.size(); ++i) {
			int m, n; //left and right pointers to expand string in opposite directions to check for palindrome property

			//if outside of range of previous largest palindrome, start search from scratch
			if (i > right) {
				lengths[i] = 0; m = i - 1; n = i + 1;
			}
			//otherwise we can simplify search knowing the left side of largest palindrome and using its mirror property,
			//we can predict minimum possible palindrome lengths on the left side and skip unnecessary searching
			else { 
				int i2 = center - (i - center); //palindrome is mirrored around center, so find mirror index

				//if mirrored-palindrome on the left is entirely within current longest palindrome, it's safe to skip
				//testing this center, because it will be the same as that on the left
				if (lengths[i2] < right - i) { 

					lengths[i] = lengths[i2];
					m = -1;
				}
				//otherwise we can skip the few 'known' characters from mirror property
				else {
					lengths[i] = right - i; //move the pointer just outside of previous palindrome
					n = right + 1; m = i - (n - i);
				}
			}

			//expand characters at the current i as center and test for palindrome
			while (m >= 0 && n < s.size() && s[m] == s[n]) {
				lengths[i]++; m--; n++;
			}

			//if the new palindrome exceeds reach of the current one, set it to current
			if (i + lengths[i] > right) {
				center = i; right = i + lengths[i];
			}
		}

		//now find the index of the longest palindrome in the array
		center = 0;
		int length = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (length < lengths[i]) {
				length = lengths[i]; center = i;
			}
		}

		string result = s.substr(center - length, length * 2 + 1);
		removeBoundaries(result);
		return result;
	}

	void test() {
		string result = findLongestPalindrome("aaagrcabbad");
		cout << result << endl;
	}
};