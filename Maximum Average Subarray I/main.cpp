#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int> nums, int k) {
		double ret = accumulate(nums.begin(), nums.begin() + k, 0);

		double sum = ret;
		for (int i = k; i < nums.size(); i++)
		{
			sum = sum + nums[i] - nums[i-k];
			

			ret = max(ret, sum);
		}

		return ret / k;
	}
};


int main()
{
	Solution s;
	s.findMaxAverage({ 0,4,0,3,2 }, 1);
	return getchar();
}