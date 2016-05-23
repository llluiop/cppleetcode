#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
		{
			return nums.size();
		}

		vector<int> v;

		v.push_back(nums[0]);

		int couter = 1;
		int pre = nums[0];
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] == pre)
			{
				couter++;

				if (couter <= 2)
				{
					v.push_back(nums[i]);
				}
			}
			else
			{
				v.push_back(nums[i]);

				couter = 1;
				pre = nums[i];
			}
		}

		nums.swap(v);
		return nums.size();
	}
};

int main()
{
	Solution s;

	vector<int> num = { 1, 1, 1, 2,2,3,3,3, };
	cout << s.removeDuplicates(num);
	return getchar();
}