#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return{};
		}

		vector<vector<int>> v;
		permute(nums, 0, v);


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
			set<int> s;			
			for (size_t i = index; i < nums.size(); i++)
			{
				if (s.find(nums[i]) == s.end())
				{				
					swap(nums[index], nums[i]);
					permute(nums, index + 1, v);
					swap(nums[index], nums[i]);

					s.insert(nums[i]);
				}

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

	vector<int> num = {3, 3, 0, 0, 2, 3, 2};
	auto v = s.permuteUnique(num);
	cout << v.size();
	return getchar();
}