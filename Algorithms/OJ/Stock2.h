#include <vector>
#include <iostream>
using namespace std;

#pragma once;

class Solution {
public:

	int maxProfit(vector<int> &prices) {

		int profit = 0;

		int min = INT_MAX;
		int max = 0;

		for (auto it = prices.begin(); it != prices.end(); ++it) {
			if (*it < min) {
				min = *it;
				max = 0;
			}
			else if (*it > max) {
				max = *it;

				//perform transaction
				auto itNext = it + 1;
				if (itNext == prices.end() || *itNext <= *it) {
					int range = max - min;
					profit += range;
					min = INT_MAX;
				}
			}
		}
		return profit;
	}

	void test() {
		vector<int> prices = { 5, 2, 3, 2, 6, 6, 2, 9, 1, 0, 7, 4, 5, 0 };
		int profit = maxProfit(prices);
		cout << profit << endl;
	}
};