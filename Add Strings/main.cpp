#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1 == "") return num2;
		if (num2 == "") return num1;

		string ret;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int add_len = min(num1.length(), num2.length());
		int carry = 0;

		int i = 0;
		for (; i < add_len; i++)
		{
			auto sum = add(num1[i], num2[i], carry);
			ret.append(1, char(sum.second + '0'));
			carry = sum.first;
		}

		if (i == num1.length() && i == num2.length())
		{
			if (carry == 1)
			{
				ret.append(1, '1');
			}
		}
		else
		{
			if (i == num1.length())
			{
				for (; i < num2.length(); i++)
				{
					auto sum = add(carry+'0', num2[i], 0);
					ret.append(1, char(sum.second + '0'));
					carry = sum.first;
				}

				if (carry == 1)
				{
					ret.append(1, '1');
				}
			}
			else if (i == num2.length())
			{
				for (; i < num1.length(); i++)
				{
					auto sum = add(carry+'0', num1[i], 0);
					ret.append(1, char(sum.second + '0'));
					carry = sum.first;
				}

				if (carry == 1)
				{
					ret.append(1, '1');
				}
			}
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}

	std::pair<int, int> add(char op1, char op2, int carry)
	{
		int sum = (op1 - '0') + (op2 - '0') + carry;
		
		return make_pair(sum / 10, sum % 10);
	}
};


int main()
{
	Solution s;
	s.addStrings("584", "18");
	return getchar();
}