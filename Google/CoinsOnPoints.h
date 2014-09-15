#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
	//computes min interval in the entire set
	int findMinInterval(set<int> &coins, set<int>::iterator &it) {
		int m = INT_MAX;
		auto itLast = coins.begin();
		for (auto itCurrent = ++coins.begin(); itCurrent != coins.end(); ++itCurrent) {
			if (*itCurrent - *itLast < m) {
				m = *itCurrent - *itLast;
				it = itCurrent;				
			}
			itLast = itCurrent;
		}
		return m;
	}

	//find min interval and the iterator pointing to the 2nd element of that min interval. 
	//Try to move that element to another available point where new min is greater
	bool improve(set<int> points, set<int> &coins, int &min, set<int>::iterator &itCoin) {
		min = findMinInterval(coins, itCoin);

		while (points.size()) {
			coins.erase(itCoin);
			itCoin = coins.insert(*points.begin()).first;
			points.erase(points.begin());

			auto itCoinPrev = itCoin;
			itCoinPrev--;
			auto itCoinNext = itCoin;
			itCoinNext++;
			
			if (*itCoin - *itCoinPrev > min && (itCoinNext == coins.end() || *itCoinNext - *itCoinPrev > min)) {
				return true;
			}
		}
		return false;
	}

	//Greedy algorithm approach, works by first randomly placing coints on points.
	//Then tries to imrove by moving coin at min dist from others to the unused available position
	//in such a way so that distances between new position and neighboring points is greater than before.
	//Repeats until no more possible moves can be made. Complexity O(n*m) n=coins, m=points.
	int findOptimalPlacement(set<int> &points, int N) {
		set<int> coins;

		for (int i = 0; i < N; ++i) {
			coins.insert(*points.begin());
			points.erase(points.begin());
		}		

		int min = 0;
		set<int>::iterator itCoin;

		while (improve(points, coins, min, itCoin)) {
			points.erase(*itCoin);
			for (int c : coins)
				cout << c << " ";
			cout << endl;
		}
		return min;
	}

	void test() {
		set<int> M = { 1, 3, 4, 5, 7, 8, 11 };
		int m = findOptimalPlacement(M, 4);
		cout << m << endl;
	}
};