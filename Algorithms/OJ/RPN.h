#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#pragma once;

string operands = "+-/*";

int evaluate(int a, int b, string op)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
		return a / b;

	return 0;
}

int evalRPN(vector<string> &tokens) {

	vector<int> variables;

	for (string s : tokens)
	{
		if (operands.find(s) == string::npos)
		{
			variables.push_back(atoi(s.c_str()));
			continue;
		}

		int result = variables.back();
		variables.pop_back();
		result = evaluate(variables.back(), result, s);
		variables.back() = result;
	}

	return variables.front();
}

void  testRPN()
{
	vector<string> rpn = { "2", "1", "+", "3", "*" };
	cout << evalRPN(rpn) << endl;

	rpn = { "4", "13", "5", "/", "+" };
	cout << evalRPN(rpn) << endl;
}