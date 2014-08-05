#pragma once
void largestCommonSubstring(char *str1, char *str2, char *sstr)
{
	int longest = 0;
	int length = 0;

	char *pLongest = str1;
	char *p1 = str1;
	char *p2 = str2;
	char *str2Start = str2;

	for (str1; *str1; ++str1)
	{
		str2 = str2Start;
		
		for (str2; *str2; ++str2)
		{
			length = 0;

			for (p1 = str1, p2 = str2; 
				*p1 && *p2 && *p1 == *p2; 
				++p1, ++p2)
			{
				length++;
			}

			if (length > longest)
			{
				longest = length;
				pLongest = str1;
			}
		}
	}
	
	while (longest-- > 0)
	{
		*sstr++ = *pLongest++;
	}
}
