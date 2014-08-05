#include <map>

#pragma once

bool checkAnagrams(char *str1, char *str2)
{
	if (!str1 || !str2)
		return false;

	std::map<char, int> occurances;

	for (str1; *str1; ++str1)
	{
		occurances[*str1]++;
	}

	for (str2; *str2; ++str2)
	{
		auto it = occurances.find(*str2);
		if (it == occurances.end())
			return false;

		it->second--;
		if (it->second == 0)
			occurances.erase(it);
	}

	return occurances.empty();
}