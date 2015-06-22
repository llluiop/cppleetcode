#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int index = 0;
		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (*iter != 0)
			{
				nums[index] = *iter;

				if (&(*iter) != &(nums[index]))
				{
					*iter = 0;
				}
				index++;
			}
		}
	}
};

#endif