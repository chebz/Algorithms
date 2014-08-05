#pragma once

int numberOfCharacters(char *str, char c)
{
	int i = 0;
	char *q = str;

	while (q && *q)
	{
		if (*q == c)
			++i;
		++q;
	}
	return i;
}

int findSize(char *str)
{
	char *q = str;
	int i = 0;

	while (q && *q)
	{
		++i;
		++q;
	}
	return i;
}

bool isSubstring(char *str1, char *str2)
{
	if (!str1 || !str2)
		return false;

	for (str1; *str1; ++str1)
	{
		if (*str1 == *str2)
		{
			char *a = str1;
			char *b = str2;

			while (*a == *b && *a && *b)
			{
				a++;
				b++;
			}

			if (!*b)
				return true;
		}
	}

	return false;
}