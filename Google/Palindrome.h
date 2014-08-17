#include <iostream>
using namespace std;
#pragma once

void expand(char * l, char * r, int &longest)
{
	int length = 0;

	while (*l && *r && *l == *r)
	{
		if (l == r)
			length++;
		else
			length += 2;
		--l;
		++r;
	}

	if (length > longest)
		longest = length;
}

int longestPalindrome(char * c)
{
	int longest = 0;

	while (*c)
	{
		char *l = c;
		char *r = c;
		expand(l, r, longest);
		
		l = c;
		r = c + 1;
		expand(l, r, longest);
		++c;
	}

	return longest;
}

void palindromeTest()
{
	char *c = "abaaba";
	cout << longestPalindrome(c) << endl;
}