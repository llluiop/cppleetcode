#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
/*public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() == 0 || amount <= 0)
		{
			return 0;
		}
		sort(coins.begin(), coins.end());
		reverse(coins.begin(), coins.end());

		int min = INT_MAX;

		coins_change(coins, 0, amount, 0, min);

		return min == INT_MAX ? -1 : min;
	}

private:
	void coins_change(vector<int>& coins, int start, int amount, int k, int& min)
	{
		if (amount < 0 || k >= min)
		{
			return;
		}


		for (int i = start; i < coins.size(); i++)
		{
			if (coins[i] > amount)
				continue;

			if (coins[i] == amount)
			{
				if (k+1 < min)
				{
					min = k+1;
				}
				continue;
			}

			coins_change(coins, i, amount - coins[i], k+1, min);
		}

	}*/

public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() == 0 || amount <= 0)
		{
			return 0;
		}

		vector<int> v(amount + 1, amount+1);
		v[0] = 0;

		for (size_t i = 1; i < v.size(); i++)
		{
			for (int coin : coins)
			{
				if (coin <= i)
				{
					v[i] = min(v[i], v[i - coin] + 1);
				}
			}
		}

		return v[amount] > amount ? -1 : v[amount];

	}


};


int main()
{
	Solution s;

	vector<int> v = { 71, 440, 63, 321, 461, 310, 467, 456, 361 };
	cout<<s.coinChange(v, 9298);

	return getchar();
}