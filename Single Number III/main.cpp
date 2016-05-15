#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int tmp = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			tmp ^= nums[i];
		}

		tmp = tmp & ~(tmp - 1); //get last different bit

		int res1 = 0;
		int res2 = 0;

		for (int i:nums)
		{
			if (tmp & i)
			{
				res1 ^= i;
			}
			else
			{
				res2 ^= i;
			}
		}

		vector<int> v = { res1, res2 };
		return v;
	}
};


int main()
{
	vector<int> v = {-1, 0 };
	Solution s;
	s.singleNumber(v);
	return getchar();
}