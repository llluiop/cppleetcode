#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size() + 1;

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += i;
		}

		int vsum = 0;
		for (int i:nums)
		{
			vsum += i;
		}

		return sum - vsum;

	}
};



int main()
{
	vector<int> v = { 0, 1, 2, 4 };
	Solution s;
	s.missingNumber(v);
	return getchar();
}