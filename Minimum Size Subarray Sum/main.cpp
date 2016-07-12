#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ret = INT_MAX;

		int start = 0;
		int end = 0;

		int sum = 0;
		while (end < nums.size())
		{
			while (sum < s && end < nums.size())
			{
				sum += nums[end++];
			}

			while (sum >= s && start <= end)
			{
				ret = min(ret, end - start);
				sum -= nums[start++];
			}
		}

		return ret == INT_MAX ? 0 : ret;
	}
};


int main()
{
	Solution s;

	s.minSubArrayLen(7, vector<int>{2, 3, 1, 2, 4, 3});
	return getchar();
}