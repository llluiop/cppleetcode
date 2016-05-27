#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return{};
		}

		vector<vector<int>> v;
		for (size_t i = 0; i < nums.size(); i++)
		{
			swap(nums[0], nums[i]);
			permute(nums, 1, v);
			swap(nums[0], nums[i]);
		}

		return v;
	}

private:
	void permute(vector<int>& nums, int index, vector<vector<int>>& v)
	{
		if (index == nums.size())
		{
			v.push_back(nums);
		}
		else
		{
			for (size_t i = index; i < nums.size(); i++)
			{
				swap(nums[index], nums[i]);
				permute(nums, index+1, v);
				swap(nums[index], nums[i]);
			}
		}
	}
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};

int main()
{
	Solution s;

	vector<int> num = { 1};
	auto v = s.permute(num);
	cout<<v.size();
	return getchar();
}