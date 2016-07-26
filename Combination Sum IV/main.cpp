#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0)
		{
			return 0;
		}
		
		vector<int> dp(target + 1);
		dp[0] = 1;

		for (int i = 1; i <= target;i++)
		{
			for (auto x : nums)
			{
				if (i >= x)
					dp[i] += dp[i - x];
			}
		}

		return dp[target];
	}
};

int main()
{
	Solution s;
	cout << s.combinationSum4(vector<int>{4, 2, 1}, 32);
	return getchar();
}