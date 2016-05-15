#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//time limit exceeded
	/*int trailingZeroes(int n) {
		int count = 0;
		for (int i = 5; i <= n; i=i+5)
		{
			int tmp = i;
			while (tmp%5==0)
			{
				tmp = tmp / 5;
				count++;
			}
		}

		return count;
	}*/

	//[N/5]+[N/(5*5)]+[N/(5*5*5)]+...
	//equals: [N/5]+[(N/5)/5]+[(N/5/5)/5]+...
	int trailingZeroes(int n) {
		int count = 0;
		while (n)
		{
			count += n / 5; //how many 5 in n
			n = n / 5;  
		}

		return count;
	}
};

int main()
{
	Solution s;
	cout << s.trailingZeroes(20);
	return getchar();
}