#include <iostream>


class Solution {
public:
	int numTrees(int n) {
		if (n <= 0 )
		{
			return 0;
		}

		if (n == 1)
		{
			return 1;
		}

		int tmp = 0;

		for (int i = 1; i < n-1; i++)
		{
			tmp += numTrees(i)*numTrees(n-1 - i);
		}
		return numTrees(n - 1) * 2 + tmp;
	}
};
int main()
{
	Solution s;

	std::cout << s.numTrees(10);


	return getchar();
}