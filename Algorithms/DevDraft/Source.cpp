#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;

uint64_t av(const uint64_t &x, const uint64_t &y) {
	return x / 2 + y / 2;
}

uint64_t delta(const uint64_t &x, const uint64_t &y) {
	if (x > y)
		return x - y;
	else
		return y - x;
}

bool isEven(const uint64_t &n) {
	return n % 2 == 0;
}

uint64_t order(const uint64_t &j) {
	if (j <= 1)
		return j;

	int n = 2;
	int res = 1;
	while (res < j) {
		res = 2 * res + (isEven(n) ? 1 : -1);
		n++;
	}
	return n;
}

bool solve(uint64_t a, uint64_t b, uint64_t c) {
	uint64_t ab = delta(a, b);	
	uint64_t bc = delta(b, c);
	uint64_t ac = delta(a, c);

	if (ab == 0 && bc == 0) return false;
	if (ab == 0 || bc == 0) return true;
	if (ab == 1 && bc == 1) return false;

	bool b_ab = isEven(order(ab));
	bool b_bc = isEven(order(bc));
	bool b_ac = av(a, c) == b ? false : isEven(order(ac));
	
	return b_ab || b_bc || b_ac;
}

void test() {
	cout<<solve(10, 11, 13);
}

int main() {
	test();
	int n;
	cin >> n;

	int a, b, c;

	for (int i = 0; i < n; ++i) {
		cin >> a;
		cin >> b;
		cin >> c;

		cout << solve(a, b, c) << endl;
	}

	return 0;
}