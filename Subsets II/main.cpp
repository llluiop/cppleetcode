#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> v;
		v.push_back({});

		sort(nums.begin(), nums.end());

		queue<vector<pair<int,int>>> vv;
		int pre = !nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != pre)
			{
				vv.push({ make_pair(nums[i], i) });
				pre = nums[i];
			}

		}

		

		while (!vv.empty())
		{
			auto s = vv.front();
			vv.pop();

			vector<int> vTmp;
			for (auto ss : s)
			{
				vTmp.push_back(ss.first);
			}
			v.push_back(vTmp);

			auto last = s.back();

			if (last.second + 1 >= nums.size())
			{
				continue;
			}
			int pre = !nums[last.second+1];

			for (int i = last.second + 1; i < nums.size(); i++)
			{
				if (pre != nums[i])
				{
					auto tmp = s;
					tmp.push_back(make_pair(nums[i], i));
					vv.push(tmp);
					pre = nums[i];
				}
			}

		}
		return v;
	}
};


int main()
{
	Solution s;
	s.subsetsWithDup(vector<int>{ -1, 1, 2 });

	return getchar();
}