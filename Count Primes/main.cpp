#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


class Solution {
public:
	//time limit exceeded
// 	int countPrimes(int n) {
// 		if (n <= 1)
// 		{
// 			return 0;
// 		}
// 
// 		int count = 0;
// 
// 		for (int i = 2; i <= n; i++)
// 		{
// 			int j = 2;
// 			bool isPrime = true;
// 			while (j <= sqrt(i))
// 			{
// 				if (i % j == 0)
// 				{
// 					isPrime = false;
// 					break;
// 				}
// 
// 				++j;
// 			}
// 
// 			if (isPrime)
// 			{
// 				++count;
// 			}
// 		}
// 
// 		return count;
// 	}

	int countPrimes(int n) {
		vector<bool> b(n);

		for (int i = 2; i*i < n; i++)
		{
			if (!b[i])
			{
				for (int j = i; j * i < n; j++)
				{
					b[i*j] = true;
				}
			}
		}

		int c = 0;
		for (int i = 2; i < n; i++)
		{
			if (!b[i])
			{
				++c;
			}
		}

		return c;
	}
};



int main()
{
	Solution s;
	cout << s.countPrimes(3);
	return getchar();
}