#include <string>
#include <iostream>
using namespace std;
#pragma once;

string convert(string s, int nRows) {
	if (nRows == 1)
		return s;

	int length = s.size();
	if (length == 0)
		return "";

	int partSize = 2 * (nRows - 1);
	int nParts = length / partSize + 1;
	string result = "";

	for (int r = 0; r < nRows; ++r)
	{
		for (int i = 0; i < nParts; ++i)
		{
			int index = partSize*i + r;
			if (index >= length)
				break;

			result += s[index];

			if (r > 0 && r < nRows - 1)
			{
				index = partSize*i + partSize - r;
				if (index < length)
					result += s[index];
			}
		}
	}

	return result;
}

void testZigZag()
{
	string result = convert("PAYPALISHIRING", 3);
	cout << result << endl;
}