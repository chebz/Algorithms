#include <map>

#pragma once

bool allUnique(char *str)
{
	std::map<char, int> occurances;

	for (str; str && *str; ++str)
	{
		if (occurances.find(*str) != occurances.end())
		{
			return false;
		}
		occurances[*str] = 1;
	}
	return true;
}

bool allUniqueNoDatastructures(char *str)
{
	for (str; str && *str; ++str)
	{
		char *q = str;

		for (--q; *q; --q)
		{
			if (*q == *str)
				return false;
		}
	}
	return true;
}