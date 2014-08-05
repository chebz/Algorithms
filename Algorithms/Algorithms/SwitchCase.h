#pragma once

void switchCase(char *str)
{
	char *c = str;

	while (c && *c) //verify that c is a valid pointer and hasn't reached the end of str
	{
		//using characters instead of ascii codes is more portable and easier to read
		if (*c >= 'A' && *c <= 'Z')
			*c += ('a' - 'A');
		else if (*c >= 'a' && *c <= 'z')
			*c += ('A' - 'a');
		c++;
	}
}