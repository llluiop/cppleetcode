#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		vector<int> v(nums.end() - k, nums.end());
		for (size_t i = 0; i < nums.size()-k; i++)
		{
			v.push_back(nums[i]);
		}

		nums.swap(v);
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 1, 0 };
	s.rotate(v, 0);

	return getchar();
}