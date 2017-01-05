
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
	int totalHammingDistance(vector<int>& nums) {
		int ret = 0;

		for (int i = 0; i < 32; i++)
		{
			int count = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				count += ((nums[j] >> i) & 1);
			}

			ret += (count * (nums.size() - count));
		}

		return ret;
	}


};


int main()
{
	Solution s;
	s.totalHammingDistance(vector<int>{1337,7331});
	return getchar();
}

