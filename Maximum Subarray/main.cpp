#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN;

		int result = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			result += nums[i];
			if (result > max)
			{
				max = result;
			}

			if (result < 0)
			{
				result = 0;
			}
		}

		return max;
	}
};


int main()
{
	Solution s;

	vector<int> v = { -3, -2, -2, -3 };
	std::cout << s.maxSubArray(v);

	return getchar();
}