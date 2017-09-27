#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int> nums, int k) {
		vector<int> v;

		int sum = 0;
		v.push_back(0);
		for (int i = 0; i < nums.size(); i++)
		{
			v.push_back(sum + nums[i]);
			sum += nums[i];
		}

		int ret = 0;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i+1; j < v.size(); j++)
			{
				if (v[j] - v[i] == k)
					ret++;
			}
		}

		return ret;
	}
};


int main()
{
	Solution s;
	s.subarraySum({1,1,1
		 }, 2);
	return getchar();
}