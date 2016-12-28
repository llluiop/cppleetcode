
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;



class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int size = nums.size();
		vector<int> ret;

		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				int pos = abs(nums[i]) - 1;
				if (nums[pos] > 0)
				{
					nums[pos] = -nums[pos];
				}
			}
		}

		for (int i = 0; i < size; i++)
		{			
			if (nums[i] > 0)
			{
				ret.push_back(i + 1);
			}
		}

		return ret;
	}
};

int main()
{
	Solution s;

	s.findDisappearedNumbers(vector<int>{4, 3, 2, 7, 8, 2, 3, 1});
	return getchar();
}

