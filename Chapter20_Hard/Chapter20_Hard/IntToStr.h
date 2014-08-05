#include "RevereseString.h"

#pragma once

void convertIntToString(int number, char * str)
{
	char * q = str;

	if (number == 0)
	{
		*q++ = '0';
		*q = '\0';
		return;
	}

	if (number < 0)
	{
		*q++ = '-';
		str++;
		number *= -1;
	}

	while (number > 0)
	{
		*q++ = (number % 10) + '0';
		number /= 10;
	}

	*q = '\0';

	reverse(str);
	
	--str;
}
