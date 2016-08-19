#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> v;
		v.push_back({});

		sort(nums.begin(), nums.end());

		queue<vector<int>> vv;
		for (auto n : nums)
		{
			vv.push({ n });
		}

		while (!vv.empty())
		{
			auto s = vv.front();
			vv.pop();

			v.push_back(s);

			int last = s.back();
			for (auto n: nums)
			{
				if (n > last)
				{
					auto tmp = s;
					tmp.push_back(n);
					vv.push(tmp);
				}
			}

		}
		return v;
	}
};


int main()
{
	Solution s;
	s.subsets(vector<int>{ 1, 2, 3, 4 });

	return getchar();
}