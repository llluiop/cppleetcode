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

		/*sort(nums.begin(), nums.end());

		return nums[nums.size() - k];*/

		return search(nums, 0, nums.size() - 1, k);

	}

private:
	int search(vector<int>& nums, int low, int high, int k)
	{
		if (low <= high)
		{
			int i = pivot(nums, low, high);
			if (i - low + 1 == k)
			{
				return nums[i];
			}
			else if (i - low + 1 > k)
			{
				search(nums, low, i-1, k);
			}
			else
			{
				search(nums, i+1, high, k-(i-low+1));
			}
		}
	}


	int pivot(vector<int>& nums, int low, int high)
	{
		int tmp = nums[low];

		while (low < high)
		{
			while (low < high && nums[high] <= tmp)
				high--;

			nums[low] = nums[high];

			while (low < high && nums[low] >= tmp)
				low++;

			nums[high] = nums[low];
		}

		nums[low] = tmp;

		return low;
	}
};


int main()
{
	Solution s;
	cout << s.findKthLargest(vector<int>{-1,-1}, 2);

	return getchar();
}