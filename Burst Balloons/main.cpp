#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);

		int** dp = new int*[nums.size()];
		for (int i = 0; i < nums.size(); i++)
		{
			dp[i] = new int[nums.size()];
			for (int j = 0; j < nums.size(); j++)
			{
				dp[i][j] = 0;
			}
		}

		for (int k = 2; k < nums.size(); k++)
		{
			for (int l = 0; l < nums.size() - k; l++)
			{
				
				int r = l + k;
				for (int m = l + 1; m < r; m++)
				{
					dp[l][r] = std::max(dp[l][r], nums[l] * nums[m] * nums[r] + dp[l][m] + dp[m][r]);
				}
			}
		}	

		return dp[0][nums.size()-1];

	}
};

int main()
{
	Solution s;

	cout << s.maxCoins(vector<int>{3, 1, 5, 8});
	return getchar();
}