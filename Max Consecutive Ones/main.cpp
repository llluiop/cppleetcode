
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
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}

		int ret = 0;

		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				sum++;
			}
			else
			{
				ret = max(ret, sum);
				sum = 0;
			}
		}

		return max(ret, sum);
	}
};


int main()
{
	Solution s;
	s.findMaxConsecutiveOnes(vector<int>{ 1, 1, 0, 1, 1, 1 });
	return getchar();
}

