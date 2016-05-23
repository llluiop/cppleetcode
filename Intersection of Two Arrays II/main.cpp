#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0 || nums2.size() == 0)
		{
			return{};
		}

		vector<int> v(nums1.size() + nums2.size());

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		auto iter = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
		v.resize(iter - v.begin());

		return v;
	}
};

int main()
{
	Solution s;

	vector<int> v1 = { 3, 3, 4 };
	vector<int> v2 = { 3, 3, 2 };
	s.intersect(v1, v2);
	return getchar();
}