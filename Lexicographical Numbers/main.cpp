#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> v;
		if (n == 0)
		{
			return v;
		}

		for (int i = 1; i <= 9; i++)
		{
			if (i <= n)
			{
				v.push_back(i);
				lexical(v, i, n);
			}

		}

		return v;
	}

	void lexical(vector<int>& v, int base, int max)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (base*10+i > max)
			{
				return;
			}
			v.push_back(base * 10 + i);
			lexical(v, base * 10 + i, max);
		}
	}
};

int main()
{
	Solution s;
	s.lexicalOrder(10);
	return getchar();
}