#include "../include/stdc++.h"

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int size = nums.size();
		if (size == 0)
		{
			return 0;
		}

	    ways(nums, S, 0);
		return sum;
	}

	void ways(vector<int>& nums, int S, int k) {
		if (S == 0 && k == nums.size())
		{
			sum++;
			return;
		}

		if (k == nums.size())
		{
			return;
		}
		ways(nums, S - nums[k], k+1);
		ways(nums, S + nums[k], k+1);
	}

	int sum = 0;
};

int main() {
	Solution s;
	s.findTargetSumWays(vector<int>{1, 1, 1, 1, 1}, 3);
	return 0;
}