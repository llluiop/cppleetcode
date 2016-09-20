#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		int base = 9;
		int carry = 1;

		while (__int64(n) > (__int64(base)*__int64(carry)))
		{
			n -= base*carry;
			base *= 10;
			carry++;
		}


		int num = base / 9 + (--n / carry);

		int find = carry - n % carry;
		while (--find > 0)
		{
			num /= 10;
		}

		return num%10;
	}
};

int main()
{
	Solution s;
	s.findNthDigit(11);
	return getchar();
}