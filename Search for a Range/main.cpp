#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0 || target < nums[0] || target > nums[nums.size()-1])
		{
			return{ -1, -1 };
		}

		int low = 0;
		int high = nums.size() - 1;

		int mid = -1;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (nums[mid] == target)
			{
				break;
			}
			else if (nums[mid] > target)
			{
				high = mid - 1;;
			}
			else
			{
				low = mid + 1;
			}
		}

		int start = -1;
		int end = -1;
		if (nums[mid] == target)
		{
			start = get_start(nums, mid);
			end = get_end(nums, mid);
		}


		return{ start, end };
		
	}

private:
	int get_start(vector<int>& nums, int archor)
	{
		int target = nums[archor];

		int start = 0;
		int end = archor;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		return start;
	}

	int get_end(vector<int>& nums, int archor)
	{
		int target = nums[archor];

		int start = archor;
		int end = nums.size()-1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		return end;
	}
};

int main()
{
	Solution s;
	s.searchRange(vector<int>{ 7, 8, 8, 9, 9, 9 }, 9);
	return getchar();
}