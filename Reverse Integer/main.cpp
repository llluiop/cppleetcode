#include <iostream>

using namespace std;


class Solution {
public:
	int reverse(int x)
	{
		int tmp = 0;
		int res = 0;
		while (x != 0)
		{
			tmp = res * 10 + x % 10;
			if (x > 0 && tmp/10 < res)
			{
				return 0;
			}
			if (x < 0 && tmp/10 > res)
			{
				return 0;
			}

			res = tmp;
			x = x / 10;
		}

		return res;
	}
};


int main()
{
	Solution s;
	s.reverse(2);
	return getchar();
}