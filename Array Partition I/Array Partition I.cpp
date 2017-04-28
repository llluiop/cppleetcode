// Array Partition I.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int sum = 0;
		for (size_t i = 0; i < nums.size(); i = i+2)
		{
			sum += nums[i];
		}

		return sum;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

