#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {

		vector<vector<int>> table(n+1);
		for (int i = 0; i <= n; i++)
		{
			table[i].resize(n + 1);
		}

		return dp(1, n, table);
	}

	int dp(int s, int e, vector<vector<int>>& table)
	{
		if (s >= e) return 0;
		if (table[s][e] != 0) return table[s][e];

		int res = INT_MAX;

		for (int i = s; i < e; i++)
		{
			res = min(res, i + max(dp(s, i - 1, table), dp(i + 1, e, table)));
		}

		table[s][e] = res;
		return res;

	}
};

int main()
{
	Solution s;
	cout<<s.getMoneyAmount(10);
	return getchar();
}