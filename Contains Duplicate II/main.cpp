#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= 1)
		{
			return false;
		}

		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(nums[i]) != m.end() && i-m[nums[i]] <= k )
			{
				return true;
			}
			else
			{
				m[nums[i]] = i;
			}
		}

		return false;
	}
};

int main()
{
	vector<int> v1 = { 1, 2 };


	Solution s;
	s.containsNearbyDuplicate(v1, 2);
	return getchar();
}