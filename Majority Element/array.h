#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
// 	int majorityElement(vector<int>& nums) {
// 		std::sort(nums.begin(), nums.end());
// 		return nums[nums.size() / 2];
// 	}

	int majorityElement(vector<int>& nums) {
		int winner = 0;
		int count = 0;

		for (int x : nums)
		{
			if (count == 0)
			{
				winner = x;
			}

			(winner == x) ? count++ : count--;
		}

		return winner;
	}
};

#endif