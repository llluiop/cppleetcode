#include <iostream>


class Solution {
public:
	int integerBreak(int n) {
		if (n < 4)
		{
			return n-1;
		}

		int max = 0;

		for (int i = 2; i <= n/2; i++)
		{
			int tmp = n;
			int j = i;

			int result = 1;
			while (tmp > 1)
			{
				result *= tmp / j;
				tmp = tmp - (tmp / j);
				--j;
			}

			if (result > max)
			{
				max = result;
			}
			else
				break;
		}

		return max;
	}
};

int main()
{
	Solution s;

	std::cout << s.integerBreak(50);


	return getchar();
}