#include <iostream>
#include <vector>
using namespace std;
#pragma once;

class Solution {
public:
	typedef vector<int>::iterator it;

	bool findNextStation(vector<int> &gas, vector<int> &cost, it &itGas, it &itCost, int &g, int &c) {
		while (itGas != gas.end()) {
			if (*itGas > *itCost) return true;
			g += *itGas;
			c += *itCost;
			itGas++;
			itCost++;
		}
		return false;
	}


	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		it itGas = gas.begin();
		it itCost = cost.begin();
		it itGasStart = gas.begin();
		it itCostStart = cost.begin();

		int g = *itGas;
		int c = *itCost;
		int gt = 0;
		int ct = 0;

		while (itGas != gas.end()) {
			if (g < c) {
				if (!findNextStation(gas, cost, itGas, itCost, gt, ct))
					return -1;
				itGasStart = itGas;
				itCostStart = itCost;
				g = *itGas;
				c = *itCost;
			}
			else {
				g += *itGas;
				c += *itCost;
			}
			itGas++;
			itCost++;

			if (itGas == gas.end()) {
				g += gt; c += ct;
				if (g >= c)
					return itGasStart - gas.begin();
				else {
					itGas = itGasStart + 1;
					itCost = itCostStart + 1;
				}
			}
		}
		return -1;
	}

	//[5,0,9,4,3,3,9,9,1,2], [6,7,5,9,5,8,7,1,10,5]
	void test() {
		vector<int> gas = { 5, 0, 9, 4, 3, 3, 9, 9, 1, 2 };
		vector<int> cost = { 6, 7, 5, 9, 5, 8, 7, 1, 10, 5 };
		int n = canCompleteCircuit(gas, cost);
		cout << n << endl;
	}
};