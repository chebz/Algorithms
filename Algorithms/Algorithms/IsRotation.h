#include "Utils.h"

#pragma once

bool isRotation(char *str1, char *str2)
{
	if (!str1 || !str2)
		return false;

	int sizeDouble = findSize(str1) * 2;
	char *wrappedString = new char[sizeDouble];
		
	char *p = wrappedString;
	for (int i = 0; i < 2; ++i)
	{
		char *q = str1;

		for (q; *q; ++q)
		{
			*p = *q;
			p++;
		}
	}

	*p = '\0';
		
	return isSubstring(wrappedString, str2);
}

