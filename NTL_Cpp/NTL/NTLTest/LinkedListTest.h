#include <iostream>
#include "LinkedList.h"
using namespace std;
#pragma once

class TestHarness {
public:

	void test() {
		LinkedList<int> list;
		list.push_front(1);
		list.push_front(2);
		list.push_front(3);
		list.push_front(4);
		list.push_front(5);

		auto it = list.begin();
		while (it != list.end()) {
			int n = *it++;
			cout << n << ",";
		}
		cout << endl;
	}
};