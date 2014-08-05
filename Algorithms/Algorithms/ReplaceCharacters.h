#include "Utils.h"

#pragma once

//this allocates!
char *replaceCharacters(char *str, char c, char *replacement)
{
	if (!str)
		return nullptr;

	int n = numberOfCharacters(str, c);

	int sizeReplacement = findSize(replacement);
	int sizeOriginal = findSize(str);
	int newSize = (sizeReplacement - 1) * n + sizeOriginal + 1;

	char * result = new char[newSize];
	char * r = result;

	for (str; *str; ++str)
	{
		if (*str != c)
			*r++ = *str;
		else
		{
			char *q = replacement;

			for (q; *q; ++q)
			{
				*r++ = *q;
			}
		}
	}

	*r = '\0';
	
	return result;
}

