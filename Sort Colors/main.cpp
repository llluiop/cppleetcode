#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0;
		int white = 0;
		int blue = 0;

		for (auto i : nums)
		{
			if (i == 0)
			{
				red++;
			}
			if (i == 1)
			{
				white++;
			}
			if (i == 2)
			{
				blue++;
			}
		}

		nums.clear();

		while (red-- != 0)
		{
			nums.push_back(0);
		}

		while (white-- != 0)
		{
			nums.push_back(1);
		}

		while (blue-- != 0)
		{
			nums.push_back(2);
		}
	}
};


int main()
{
	Solution s;

	vector<int> v = { 0,1,2,0,1,2 };
	s.sortColors(v);

	return getchar();
}