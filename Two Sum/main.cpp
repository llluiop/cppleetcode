#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> indicies(nums.size());
		std::iota(std::begin(indicies), std::end(indicies), 0);
		std::sort(indicies.begin(), indicies.end(), [&nums](int a, int b) {
			return nums[a] < nums[b];
		});
		auto lo = std::begin(indicies);
		auto hi = std::end(indicies) - 1;
		while (lo < hi) {
			if (nums[*lo] + nums[*hi] < target) {
				lo++;
			}
			else if (nums[*lo] + nums[*hi] > target) {
				hi--;
			}
			else /* (nums[*lo] + nums[*hi] == target) */ {
				break;
			}
		}
		return std::vector<int> { *lo, *hi };
	}
};


int main()
{
	Solution s;
	auto v = s.twoSum(vector<int>{3, 4, 2, 5, 6, 1, 8, 9}, 15);
	return getchar();
}