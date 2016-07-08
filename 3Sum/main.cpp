#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() <3)
			return{};

		vector<vector<int>> v;
		sort(nums.begin(), nums.end());
		int i = 0;
		for (; i < nums.size(); i++)
		{
			if (i != 0 && nums[i] == nums[i-1])
			{
				continue;
			}
			int low = i + 1;
			int high = nums.size() - 1;

			while (low < high)
			{
				int sum = nums[low] + nums[high];
				if (sum + nums[i] == 0)
				{
					v.push_back({ nums[i], nums[low], nums[high] });
					while (++low<high && nums[low] == nums[low - 1]);
					while (--high>low && nums[high] == nums[high + 1]);
				}
				else if (sum + nums[i] > 0)
				{
					high--;
				}
				else
				{
					low++;
				}
			}

		}

		return v;
	}
};


int main()
{
	Solution s;

	s.threeSum(vector<int>{ -1, 0, 1, 2, -1, -4 });
	return getchar();
}