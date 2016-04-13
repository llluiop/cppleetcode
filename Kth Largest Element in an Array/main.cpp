#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 1)
		{
			return nums[0];
		}

		sort(nums.begin(), nums.end());

		return nums[nums.size() - k];

	}
};


int main()
{
	Solution s;
	cout << s.findKthLargest(vector<int>{3, 2, 1, 5, 6, 4}, 2);

	return getchar();
}