#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
		{
			return 0;
		}

		int curMaxProfit = 0;
		int curMin = prices[0];

		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] < curMin)
			{
				curMin = prices[i];
			}

			curMaxProfit = max(curMaxProfit, prices[i] - curMin);

		}

		return curMaxProfit;
	}
};



int main()
{
	vector<int> v = { -1, 0, 3, 5 };
	Solution s;
	s.maxProfit(v);
	return getchar();
}