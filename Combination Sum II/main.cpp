#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.size() == 0)
		{
			return{};
		}

		sort(candidates.begin(), candidates.end());

		vector<vector<int>> v;

		vector<int> c;
		combination(v, candidates, c, target, 0);
		return v;
	}

	void combination(vector<vector<int>>& v, vector<int>& candidates, vector<int> c, int target, int index)
	{
		if (target < 0) return;

		if (target == 0)
		{
			v.push_back(c);
		}


		auto size = candidates.size();
		for (int i = index; i < size; i++)
		{
			if (i >= index+1 && candidates[i] == candidates[i - 1]) continue;

			c.push_back(candidates[i]);
			combination(v, candidates, c, target - candidates[i], i+1);
			c.pop_back();
		}
	}
};

int main()
{
	Solution s;
	s.combinationSum2(vector<int>{10, 1, 2, 7, 6, 1, 5}, 8);
	return getchar();
}