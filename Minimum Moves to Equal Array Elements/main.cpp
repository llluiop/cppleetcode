
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
	int minMoves(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}

		int min_num = INT_MAX; 
		for (auto n : nums)
		{
			min_num = min(n, min_num);
		}

		int diff = 0;
		for (auto n : nums)
		{
			if (n != min_num)
			{
				diff += (n - min_num);
			}
		}

		return diff ;
	}
};


int main()
{
	Solution s;
	s.minMoves(vector<int>({ 1,1,3 }));
	return getchar();
}

