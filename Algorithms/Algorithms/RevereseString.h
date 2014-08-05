#pragma once

void reverse(char * str)
{
	char *p = str;

	while (p && *p)
		++p;

	for (--p; p > str; ++str, --p)
	{
		*str ^= *p;
		*p ^= *str;
		*str ^= *p;
	}
}

