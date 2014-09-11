#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#pragma once;

class Solution {
public:
	int calcMax(int a, int b) {
		return a > b ? a : b;
	}

	int calcMaxProfitReverse(vector<int> &prices, int start, int end, int &imin, int &imax) {
		int maxProfit = 0;
		int min = INT_MAX;
		int max = 0;
		int imaxCur = start;
		for (int i = start; i <= end; ++i) {
			if (prices[i] > max && i < end) {
				max = prices[i];
				imaxCur = i;
				min = INT_MAX;
			}
			else if (prices[i] < min) {
				min = prices[i];
				if (max - min >= maxProfit) {
					maxProfit = max - min;
					imin = i;
					imax = imaxCur;
				}
			}
		}
		return maxProfit;
	}

	int calcMaxProfit(vector<int> &prices, int start, int end, int &imin, int &imax) {
		int maxProfit = 0;
		int min = INT_MAX;
		int max = 0;
		int iminCur = start;
		for (int i = start; i <= end; ++i) {
			if (prices[i] < min) {
				min = prices[i];
				iminCur = i;
				max = 0;
			}
			else if (prices[i] > max) {
				max = prices[i];
				if (max - min >= maxProfit) {
					maxProfit = max - min;
					imax = i;
					imin = iminCur;
				}
			}
		}
		return maxProfit;
	}

	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if (n == 0) return 0;

		int imax = 0;
		int imin = 0;
		int imaxR = 0;
		int iminR = 0;
		int t1 = 0;
		int t2 = 0;

		int c = calcMaxProfit(prices, 0, n - 1, imin, imax);
		int p1 = calcMaxProfit(prices, 0, imin, t1, t2);
		int p2 = calcMaxProfit(prices, imax, n-1, t1, t2);
		int maxProfitRev = calcMaxProfitReverse(prices, imin, imax, iminR, imaxR);
		int p3 = calcMaxProfit(prices, imin, iminR, t1, t2);
		int p4 = calcMaxProfit(prices, imaxR, imax, t1, t2);
		vector<int> profits1 = { p1, p2, p3, p4 };
		vector<int> profits2 = { p1, p2, c };
		std::sort(profits1.begin(), profits1.end());
		std::sort(profits2.begin(), profits2.end());
		int maxProfit1 = *(profits1.end() - 1) + *(profits1.end() - 2);
		int maxProfit2 = *(profits2.end() - 1) + *(profits2.end() - 2);
		int maxProfit = calcMax(maxProfit1, maxProfit2);
		return maxProfit;
	}

	void test() {
		vector<int> prices = { 8, 3, 6, 2, 8, 8, 8, 4, 2, 0, 7, 2, 9, 4, 9 };
		int profit = maxProfit(prices);
		cout << profit << endl;
	}
};