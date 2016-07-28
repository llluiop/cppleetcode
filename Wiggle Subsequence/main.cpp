#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int ret = 0;
		int count1 = 1;
		int count2 = 1;

		wiggle(nums, 1, nums[0], count1, true);
		wiggle(nums, 1, nums[0], count2, false);

		return max(count1, count2);
	}


	void wiggle(vector<int>& nums, int index, int pre, int& count, bool bCmp)
	{
		if (index >= nums.size())
		{
			return;
		}

		if ((nums[index] - pre > 0 && bCmp == true) || (nums[index] - pre < 0 && bCmp == false))
		{
			wiggle(nums, index+1, nums[index], ++count, !bCmp);
		}
		else
		{
			wiggle(nums, index + 1, nums[index], count, bCmp);
		}
		
	}
};
int main()
{
	Solution s;
	cout << s.wiggleMaxLength(vector<int>{1, 7, 4, 9, 2, 5});
	return getchar();
}