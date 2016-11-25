
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
#include <vector>
using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int max1 = INT_MIN;
		int max2 = INT_MIN;
		int max3 = INT_MIN;

		int min = INT_MAX;

		for (auto n : nums)
		{
			if (n > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = n;
			}
			else if (n > max2 && n < max1)
			{
				max3 = max2;
				max2 = n;
			}
			else if (n > max3 && n < max2)
			{
				max3 = n;
			}

			if (n < min)
			{
				min = n;
			}
		}

		return (min <= max3 && max2 > max3) ? max3 : max1;
	}
};


int main()
{
	Solution s;
	s.thirdMax(vector<int>({ 1, -2147483648, 2 }));
	return getchar();
}

