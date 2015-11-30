#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		auto iter = unique(nums.begin(), nums.end());
		nums.resize(distance(nums.begin(), iter));
		return nums.size();
	}
};

int main()
{
	Solution s;

	vector<int> num = { 1, 1, 1, 2, 2, 3, 4, 4, 6, 6, 7 };
	cout << s.removeDuplicates(num);
	return getchar();
}