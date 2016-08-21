#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (primes.size() == 0)
		{
			return 1;
		}

		int ret[100000] = { 0 };
		ret[0] = 1;

		int index = 0;

		vector<int> base(primes.size());

		while (index < n)
		{
			for (int i = 0; i < primes.size(); i++)
			{				
				while (base[i] <= index && ret[index] >= primes[i]*ret[base[i]])
				{
					base[i]++;
				}

			}

			int min = INT_MAX;
			int minIndex = 0;
			for (int i = 0; i < base.size(); i++)
			{
				if (primes[i] * ret[base[i]] < min)
				{
					min = primes[i] * ret[base[i]];
					minIndex = i;
				}
			}
			ret[++index] = min;
			base[minIndex]++;
		}

		return ret[n-1];
	}
};


int main()
{
	Solution s;

	cout << s.nthSuperUglyNumber(10000, vector<int>{2, 7, 13, 19});
	return getchar();
}