#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int* ugly = new int[n];
		for (int i = 0; i < n; i++)
		{
			ugly[i] = 0;
		}
		ugly[0] = 1;
		

		int i = 0;
		int k = 0;
		int j = 0;


		int index = 1;
		while (index < n)
		{
			ugly[index] = std::min(ugly[i]*2, std::min(ugly[k]*3, ugly[j]*5));

			while (ugly[i] * 2 <= ugly[index])
			{				
				i++;
			}

			while (ugly[k] * 3 <= ugly[index])
			{				
				k++;
			}

			while (ugly[j] * 5 <= ugly[index])
			{				
				j++;
			}	

			index++;

		}

		return ugly[n-1];

	}
};


int main()
{
	Solution s;

	cout << s.nthUglyNumber(30);
	return getchar();
}
