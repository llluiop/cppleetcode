#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int result = 0;
		stack<int> ops;

		for (auto token : tokens)
		{
			if (isOp(token))
			{
				int op1 = ops.top();
				ops.pop();
				int op2 = ops.top();
				ops.pop();

				ops.push(compute(token, op1, op2));
			}
			else
			{
				ops.push(atoi(token.c_str()));
			}
		}

		return ops.top();
	}

private:
	bool isOp(string s)
	{
		return s == "+" ||
			s == "-" ||
			s == "*" ||
			s == "/";
	}

	int compute(string op, int op1, int op2)
	{
		if (op == "+")
		{
			return op2 + op1;
		}
		if (op == "-")
		{
			return op2 - op1;
		}
		if (op == "*")
		{
			return op2 * op1;
		}
		if (op == "/")
		{
			return op2 / op1;
		}

		return 0;
	}
};


int main()
{
	Solution trie;
	trie.evalRPN(vector<string>{"2", "1", "+", "3", "*"});


	return getchar();
}