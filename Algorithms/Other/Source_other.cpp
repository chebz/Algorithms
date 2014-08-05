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

	int n;
	cin >> n;
	return 0;
}