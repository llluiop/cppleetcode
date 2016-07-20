#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> v;
		if (nums1.empty() || nums2.empty() || k <= 0)
			return v;

		auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
			return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> qu(comp);

		qu.emplace(0, 0);
		while (!qu.empty() && k-->0)
		{
			auto idx = qu.top(); qu.pop();

			v.emplace_back(nums1[idx.first], nums2[idx.second]);
			if (idx.first + 1 < nums1.size())
			{
				qu.emplace(idx.first + 1, idx.second);
			}

			if (idx.first == 0 && idx.second + 1 < nums2.size())
			{
				qu.emplace(idx.first, idx.second + 1);
			}
		}

 		return v;
	}
};

int main()
{
	Solution s;
	s.kSmallestPairs(vector<int>{1, 7, 11}, vector<int>{2, 4, 6}, 5);
	return getchar();
}