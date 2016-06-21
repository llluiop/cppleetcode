
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		int* dp = new int[n + 1];
		for (size_t i = 0; i <= n; i++)
		{
			dp[i] = INT_MAX;
		}

		for (int i = 0; i*i <= n; i++)
		{
			dp[i*i] = 1;
		}

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; i + j*j <= n; j++)
			{
				dp[i + j*j] = min(dp[i] + 1, dp[i + j*j]);				
			}
		}

		return dp[n];
	}

};


int main()
{
	Solution s;

	cout << s.numSquares(13);
	return getchar();
}
