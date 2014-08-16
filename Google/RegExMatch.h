#include <iostream>
using namespace std;

#pragma once
bool isMatch(char s, char p)
{
	if (s == p || p == '.')
		return true;
	return false;
}

bool isEmpty(const char *p)
{
	char previous = '\0';
	while (*p)
	{
		if (*p != '*')
		{
			if (!previous)
				previous = *p;
			else
				return false;
		}
		else
		{
			previous = '\0';
		}
		p++;
	}
	return !previous;
}

bool isMatch(const char *s, const char *p)
{
	char previous;
	char current = *p;
	char next;
	bool mismatch = false;
	const char *q;

	while (*s && *p)
	{
		next = *(p + 1);
		if (next == '*')
		{
			q = p + 2;
			if (isMatch(s, q))
				return true;
		}

		if (isMatch(*s, current) && !mismatch)
		{
			s++;
			if (next != '*')
			{
				previous = current;
				current = *(++p);
			}
		}
		else if(current == '*')
		{
			p++;
		}
		else
		{
			return false;
		}
	}

	if (*s)
		return false;

	if (!isEmpty(p))
		return false;

	return true;
}


void testIsMatch()
{
	cout << isMatch("bbbba", ".*a*a") << endl;

	cout << isMatch("aa", "a") << endl;
	cout << isMatch("aa", "aa") << endl;
	cout << isMatch("aaa", "aa") << endl;
	cout << isMatch("aa", "a*") << endl;
	cout << isMatch("aa", ".*") << endl;
	cout << isMatch("ab", ".*") << endl;
	cout << isMatch("aab", "c*a*b") << endl;
	cout << isMatch("ab", ".*c") << endl;
	cout << isMatch("aaa", "a*a") << endl;
	cout << isMatch("a", "ab*") << endl;
}