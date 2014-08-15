#include <iostream>
using namespace std;

void explore(int **data, bool **visited, int width, int height, int x, int y)
{
	if (visited[y][x])
		return;

	visited[y][x] = true;

	if (data[y][x] == 1)
		return;

	//check north
	if (y > 0 && data[y - 1][x] == 0)
		explore(data, visited, width, height, x, y - 1);

	//check east
	if (x < width + 1 && data[y][x + 1] == 0)
		explore(data, visited, width, height, x + 1, y);

	//check south
	if (y < height - 1 && data[y + 1][x] == 0)
		explore(data, visited, width, height, x, y + 1);

	//check west
	if (x > 0 && data[y][x - 1] == 0)
		explore(data, visited, width, height, x - 1, y);
}

int countRegions(int **data, int width, int height)
{
	//allocate visited
	bool **visited = new bool*[height];
	for (int y = 0; y < height; ++y)
	{
		visited[y] = new bool[width];
		for (int x = 0; x < width; ++x)
		{
			visited[y][x] = false;
		}
	}

	int regions = 0;

	//step through data
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (visited[y][x])
				continue;
			if (data[y][x] == 1)
				continue;
			explore(data, visited, width, height, x, y);
			regions++;
		}
	}


	for (int y = 0; y < height; ++y)
	{
		delete[] visited[y];
	}
	delete[] visited;

	return regions;
}

void countDisjointsTest()
{
	int **data = new int*[4];
	data[0] = new int[5] { 1, 1, 1, 1, 1};
	data[1] = new int[5] { 1, 0, 1, 0, 1};
	data[2] = new int[5] { 1, 0, 0, 0, 1};
	data[3] = new int[5] { 1, 1, 1, 1, 0};

	int width = 5;
	int height = 4;

	int regions = countRegions(data, width, height);
	cout << regions << endl;

	for (int y = 0; y < height; ++y)
	{
		delete[] data[y];
	}
	delete[] data;
}
