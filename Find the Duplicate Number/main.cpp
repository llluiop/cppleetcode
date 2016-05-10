#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int low = 1;
		int high = nums.size()-1;


		while (low < high)
		{
			int mid = low + (high - low) / 2;
			int counter = 0;

			for (auto n : nums)
			{
				if (n <= mid)
					counter++;
			}

			if (counter > mid)
			{
				high = mid;
			}
			else
			{
				low = mid+1;
			}			
		}

		return low;
	}
};
int main()
{
	Solution s;

	vector<int> v = { 1, 3, 4, 2, 1 };
	s.findDuplicate(v);

	return getchar();
}