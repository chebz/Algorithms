#pragma once

void removeDuplicateCharacters(char *str, char *out)
{
	if (!str || !out)
		return;

	for (str; *str; ++str)
	{
		char *q = str;
		bool duplicate = false;

		for (--q; *q; --q)
		{
			if (*str == *q)
			{
				duplicate = true;
				break;
			}
		}

		if (!duplicate)
			*out++ = *str;	
	}
}