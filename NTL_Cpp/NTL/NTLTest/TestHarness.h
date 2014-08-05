#include "NTL.h"
#include <time.h>
#include <string.h>

#pragma once
class TestHarness
{
	clock_t oStartTime;
	clock_t oEndTime;

public:
	TestHarness();
	~TestHarness();

	void runTests();
	void test_swap();
	void test_linkedList();

private:
	void timerStart();
	void timerEnd(const std::string& output);
};

