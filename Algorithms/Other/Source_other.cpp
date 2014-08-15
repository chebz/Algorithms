#include <iostream>
#include <vector>
#include <string>
#include "LargestDistance.h"

using namespace std;

void LargestDistanceTest()
{
	string str = "**#*##*";
	int n = largestDistance(str);
	cout << n << endl;
}

int main()
{
	LargestDistanceTest();

	int a = (8 >> 2) * (1 << 4); //32
	int b = ((16 + 32) & 16) >> 2; //4
		int c = (16 >> (5 % 3)) | 2; //6
		bool d = 0x10 == 1 << 1; //false

	int n;
	cin >> n;
	return 0;
}