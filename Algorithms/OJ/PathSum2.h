#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> pathSum() {
		return{ { 1, 2, 3 } };
	}

	void test() {
		vector<vector<int>> vectors = pathSum();

		for (auto v : vectors) {
			for (int n : v) {
				cout << n << ", ";
			}
		}
	}
};