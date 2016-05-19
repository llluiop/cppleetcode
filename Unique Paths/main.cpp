#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	Solution()
	{
		for (int i = 0; i <= 100; i++)
			for (int j = 0; j <= 100; j++)
		{
			cache[i][j] = -1;
		}
	}
	int uniquePaths(int m, int n) {
		if (m <= 1)
		{
			return m;
		}

		if (n <= 1)
		{
			return n;
		}

		//int result = 0;
		//path(m, n, result, 1, 1);

		//return result;

		return path(m, n);
	}

	void path(int m, int n, int& result, int right, int down)
	{
		if (right == m && down == n)
		{
			result++;
			return;
		}

		if (right > m || down > n)
		{
			return;
		}

		if (right < m && down <= n)
		{
			path(m, n, result, right + 1, down);
		}

		if (right <= m && down < n)
		{
			path(m, n, result, right, down + 1);
		}

	}

	int path(int m, int n)
	{
		if (m == 1)
		{
			return 1;
		}

		if (n == 1)
		{
			return 1;
		}

		if (cache[m][n] != -1)
		{
			return cache[m][n];
		}

		int result = path(m - 1, n) + path(m, n - 1);
		cache[m][n] = result;

		return result;
	}

	int cache[101][101];
};


int main()
{
	Solution s;
	cout<<s.uniquePaths(23,12);
	return getchar();
}