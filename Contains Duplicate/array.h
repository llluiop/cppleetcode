#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
// 		map<int, int> m;
// 		for (auto x:nums)
// 		{
// 			if (m.find(x) != m.end())
// 			{
// 				return true;
// 			}
// 			else
// 			{
// 				m[x] = 0;
// 			}
// 		}
// 
// 		return false;

		// a better solution use set: 102ms->52ms [11/19/2015 liuyu]
		set<int> s(nums.begin(), nums.end());
		return s.size() != nums.size();
	}
};

#endif