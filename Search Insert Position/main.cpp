#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] >= target)
			{
				return i;
			}
		}

		return nums.size();
	}
};


int main()
{
	Solution s;

	vector<int> num = { 1, 3, 5, 6 };
	cout << s.searchInsert(num, 2);
	cout << s.searchInsert(num, 7);
	cout << s.searchInsert(num, 0);
	return getchar();
}