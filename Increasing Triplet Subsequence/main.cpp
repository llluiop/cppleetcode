#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

class Solution {
public:
	bool increasingTriplet(const vector<int>& nums) {
		int min = INT_MAX;
		int mid = INT_MAX;
		for (auto n : nums)
		{
			if (n < min)
			{
				min = n;
			}
			else if (n > min)
			{
				if (mid < n)
					return true;
				mid = n;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.increasingTriplet(vector<int>{1,2,3});

	return getchar();
}