
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
#include <vector>
using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}

		sort(nums.begin(), nums.end());
		int mid = nums[nums.size() / 2];

		int moves = 0;
		for (auto n : nums)
		{
			moves += abs(n - mid);
		}

		return moves;
	}
};


int main()
{
	Solution s;
	s.minMoves2(vector<int>({ 1, 1, 3 }));
	return getchar();
}

