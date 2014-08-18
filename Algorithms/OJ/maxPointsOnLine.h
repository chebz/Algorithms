#include <vector>
#include <unordered_map>
#include <iostream>
#include <climits>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct  Equation
{
	float m;
	float b;
	int c;
};

Equation getEquation(Point &pA, Point &pB)
{
	Equation eq;
	eq.m = (float)(pB.y - pA.y) / (float)(pB.x - pA.x);
	eq.b = pA.y - eq.m * pA.x;
	return eq;
}

bool equals(float a, float b)
{
	if (a == b)
		return true;
	if (isinf(a) && isinf(b))
		return true;
	if (isnan(a) || isnan(b))
		return true;
	return false;
}

bool incEquation(vector<Equation> &equations, Equation &in)
{
	for (auto it = equations.begin(); it != equations.end(); ++it)
	{
		if (equals((*it).m, in.m) && equals((*it).b, in.b))
		{
			(*it).c++;
		}
	}
	return false;
}

int maxCount(vector<Equation> &equations)
{
	int max = 0;
	for (auto eq : equations)
	{
		if (eq.c > max)
			max = eq.c;
	}
	return max;
}

int maxPoints(vector<Point> &points) {
	if (points.size() == 0)
		return 0;
	if (points.size() == 1)
		return 1;

	auto it = points.begin();

	vector<Equation> equations;

	while (it + 1 != points.end())
	{
		Point &pA = *it;
		Point &pB = *(it + 1);
		Equation in = getEquation(pA, pB);
		if (!incEquation(equations, in))
		{
			in.c = 2;
			equations.push_back(in);
		}

		it++;
	}

	return maxCount(equations);
}



void testMaxPoints()
{
	vector<Point> points = { Point(0, 0) };
	int max = maxPoints(points);
	cout << max << endl;
	
	points = { Point(3, 10), Point(0, 2), Point(0, 2), Point(3, 10) };
	max = maxPoints(points);
	cout << max << endl;

	
	points = { Point(84, 250), Point(0, 0), Point(1, 0), Point(0, -70), Point(0, -70), Point(1, -1), Point(21, 10), Point(42, 90), Point(-42, -230) };
	max = maxPoints(points);
	cout << max << endl;
}

/*
Different output than in local IDE
Input:	[(3,10),(0,2),(0,2),(3,10)]
Output:	3
Expected:	4
*/