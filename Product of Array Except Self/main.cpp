#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> tmp(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++)
		{
			tmp[i] = tmp[i - 1] * nums[i - 1];
		}

		int rightProduct = nums.back();
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			tmp[i] *= rightProduct;
			rightProduct *= nums[i];
		}

		return tmp;
	}


};



int main()
{
	vector<int> v = { 1, 2, 3, 4 };
	Solution s;
	s.productExceptSelf(v);
	return getchar();
}