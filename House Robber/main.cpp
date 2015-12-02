#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// time limit exceeded
	/*int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}

		return max(rob_(nums, 0), rob_(nums, 1));
	}

private:
	int rob_(vector<int>& nums, int index)
	{
		if (index >= nums.size())
		{
			return 0;
		}

		int now = nums[index];
		return max((now + rob_(nums, index + 2)), (now + rob_(nums, index + 3)));
	}*/



	int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}

		vector<int> cached(nums.size(), -1);

		return robbery(nums, 0, cached);
	}

private:
	int robbery(vector<int>& nums, int index, vector<int>& cached)
	{
		if (index >= nums.size())
		{
			return 0;
		}

		// if we don't use cached, it will be time-out
		if (cached.at(index) >= 0)
		{
			return cached.at(index);
		}

		int robit = nums.at(index) + robbery(nums, index + 2, cached);
		int notrobit = robbery(nums, index + 1, cached);

		int val = max(robit, notrobit);
		cached.at(index) = val;
		return val;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{
	vector<int> v = { 1, 3, 4, 5 };
	
	Solution s;
	cout << s.rob(v);
	return getchar();
}