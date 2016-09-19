#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() <= 2)
		{
			sort(nums.begin(), nums.end());
			return nums[nums.size() - 1];
		}

		int* dp = new int[nums.size()];
		for (int i = 0; i < nums.size(); i++)
			dp[i] = 0;

		dp[1] = nums[0];

		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}

		int maxcount = dp[nums.size() - 1];

		dp[1] = nums[1];
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}

		maxcount = max(maxcount, dp[nums.size() - 1]);

		return maxcount;
	}

};

int main()
{
	Solution s;
	s.rob(vector<int>{1,2,1,1});
	return getchar();
}