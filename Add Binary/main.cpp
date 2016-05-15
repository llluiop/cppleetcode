#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		stringstream ss;

		int carry = 0;
		int i = a.size() - 1;
		int j = b.size() - 1;

		while (i >= 0 || j >= 0) //note this condition!!!
		{
			int sum = (i < 0 ? 0 : toValue(a[i])) + (j < 0 ? 0 : toValue(b[j])) + carry; //if either of two strings is out of range, make it 0 

			if (sum >= 2)
			{
				ss << (sum -2);
				carry = 1;
			}
			else
			{
				ss << sum;
				carry = 0;
			}

			--i;
			--j;
		}

		if (carry == 1)
		{
			ss << 1;
		}

		string s = ss.str();
		reverse(s.begin(), s.end());

		return s;
	}

private:
	int toValue(char c)
	{
		return c - '0';
	}

	
};


int main()
{
	Solution s;
	string secret = "110";
	string guess = "10";

	cout << s.addBinary(secret, guess);
	return getchar();
}