#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
		{
			return 0;
		}

		int sum = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i]-prices[i-1] > 0)
			{
				sum += prices[i] - prices[i - 1];
			}
		}

		return sum;
	}
};


int main()
{
	vector<int> v = { -1, 0 , 3, 5};
	Solution s;
	s.maxProfit(v);
	return getchar();
}