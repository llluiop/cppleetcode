#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> vs;
		if (nums.size() >= 4)
		{
			vector<int> v;
			sort(nums.begin(), nums.end());
			foursum_(0, target, nums, v, vs);
		}
		
		return vs;
	}

	void foursum_(int index, int target, vector<int>& nums, vector<int> v, vector<vector<int>>& vs)
	{
		if (v.size() == 2)
		{
			int low = index;
			int high = nums.size() - 1;
			while (low < high)
			{
				int sum = nums[low] + nums[high];
				if (sum == target)
				{
					v.push_back(nums[low]);
					v.push_back(nums[high]);

					vs.push_back(v);

					v.pop_back();
					v.pop_back();

					while (++low < high && nums[low] == nums[low-1])
					{
					}

					while (low < --high && nums[high] == nums[high+1])
					{
					}
					//low++; 
					//high--;
				}
				else if (sum > target)
				{
					high--;
				}
				else
				{
					low++;
				}
			}

			return;
		}


		for (int i = index; i < nums.size(); i++)
		{
			if (i != index && nums[i] == nums[i-1])
			{
				continue;
			}
			v.push_back(nums[i]);
			foursum_(i + 1, target - nums[i], nums, v, vs);
			v.pop_back();
		}		
	}
};


int main()
{
	Solution s;

	s.fourSum(vector<int>{ 0,0,0,0 }, 0);
	return getchar();
}