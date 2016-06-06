#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxWater = 0;

		int minHeight = INT_MIN;
		for (size_t i = 0; i < height.size(); i++)
		{
			if (height[i] <= minHeight)
			{
				continue;
			}

			minHeight = height[i];

			int minInterHeight = INT_MIN;
			for (size_t j = height.size() - 1; j > i; j--)
			{
				if (height[j] <= minInterHeight)
				{
					continue;
				}

				minInterHeight = height[j];

				int x = j - i;
				int y = std::min(height[i], height[j]);
				if (maxWater < x * y)
				{
					maxWater = x * y;
				}
			}
		}

		return maxWater;

	}
};

int main()
{
	Solution s;

	vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto v = s.maxArea(num);
	cout << v;
	return getchar();
}