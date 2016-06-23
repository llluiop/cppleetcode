#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int size = nums.size();

		int low = 0;
		int high = size - 1;
		int mid = (high - low) / 2;

		while (low < high)
		{	
			mid = (high + low) / 2;

			if (nums[mid] > nums[high] && nums[mid] >= nums[low])
			{
				low = mid + 1;
			}
			else 
			{
				high = mid;
			}
		}

		return nums[high];
	}
};

int main()
{
	Solution s;

	cout << s.findMin(vector<int>{2, 1});
	return getchar();
}
