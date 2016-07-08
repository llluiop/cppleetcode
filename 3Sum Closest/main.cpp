#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() <3)
			return{};

		int closest = INT_MAX;
		int ret = 0;

		sort(nums.begin(), nums.end());
		int i = 0;
		for (; i < nums.size(); i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			int low = i + 1;
			int high = nums.size() - 1;

			while (low < high)
			{
				int sum = nums[low] + nums[high] + nums[i];
				if (sum == target)
				{
					return target;
					//v.push_back({ nums[i], nums[low], nums[high] });
					//while (++low<high && nums[low] == nums[low - 1]);
					//while (--high>low && nums[high] == nums[high + 1]);
				}
				else if (sum > target)
				{
					if (abs(sum - target) < closest)
					{
						closest = abs(sum - target);
						ret = sum;
					}
					high--;
				}
				else
				{
					if (abs(sum - target) < closest)
					{
						closest = abs(sum - target);
						ret = sum;
					}
					low++;
				}
			}

		}

		return ret;
	}
};


int main()
{
	Solution s;

	s.threeSumClosest(vector<int>{1,1,-1 }, 2);
	return getchar();
}