
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() <= 1)
		{
			return false;
		}

		int total = 0;
	

		for (int num : nums) {
			total += num;
		}

		if(total % 2 != 0)
		{
			return false;
		}

		bool **dp = new bool *[nums.size() + 1];
		for (int i = 0; i < nums.size() + 1;i++)
		{
			dp[i] = new bool[total / 2 + 1];
		}

		dp[0][0] = true;

		for (int i = 1; i < nums.size() + 1; i++) {
			dp[i][0] = true;
		}

		for (int j = 1; j < total / 2 + 1; j++) {
			dp[0][j] = false;
		}



		for (int i = 1; i < nums.size() + 1; i++)
		{
			for (int j = 1; j < (total/2)+1; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (nums[i-1] <= j)
				{
					dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i-1]];
				}
			}
		}

		return dp[nums.size()][total / 2];
	}
};


int main()
{
	Solution s;
	s.canPartition(vector<int>({ 3, 10, 5, 25, 2, 8 }));
	return getchar();
}

