#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.size() == 0) return{};

		int n = nums.size();
		vector<int> dp(n, 1);
		vector<int> path(n, -1);

		sort(nums.begin(), nums.end());

		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (nums[i] % nums[j] == 0)
				{
					if (dp[i] < dp[j] + 1)
					{
						path[i] = j;
					}
					dp[i] = max(dp[i], 1 + dp[j]);

				}
			}
		}

		auto index = distance(dp.begin(), max_element(dp.begin(), dp.end()));

		vector<int> result;
		while (index != -1)
		{
			result.push_back(nums[index]);
			index = path[index];
		}
		reverse(result.begin(), result.end());

		return result;
	}
};

int main()
{
	Solution s;

	s.largestDivisibleSubset(vector<int>{1, 2, 3, 4, 5});
	return getchar();
}
