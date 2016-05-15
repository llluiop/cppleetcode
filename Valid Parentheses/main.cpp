#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 != 0)
		{
			return false;
		}

		for (auto c : s)
		{
			if (isLeft(c))
			{
				stack_.push(c);
			}
			else
			{
				if (stack_.empty())
				{
					return false;
				}

				char top = stack_.top();
				stack_.pop();

				if (!isValidCharater(top, c))
					return false;
			}
		}

		return stack_.empty();
	}

private:
	bool isLeft(char c)
	{
		if (c == '(' || c == '[' || c== '{')
		{
			return true;
		}

		return false;
	}

	bool isValidCharater(char left, char right)
	{
		if (left == '(' && right == ')')
		{
			return true;
		}

		if (left == '[' && right == ']')
		{
			return true;
		}

		if (left == '{' && right == '}')
		{
			return true;
		}

		return false;
	}

	stack<char> stack_;
};


int main()
{
	Solution s;
	s.isValid("()[]{}");
	return getchar();
}