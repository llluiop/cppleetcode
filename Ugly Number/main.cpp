#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
	Solution()
	{
		uglys[0] = 1;
		int t2 = 0;
		int t3 = 0;
		int t5 = 0;
		for (int i = 1; i < 2000; i++)
		{
			uglys[i] = min(min(uglys[t2] * 2, uglys[t3] * 3), uglys[t5] * 5);

			while ((long long)uglys[t2]*2 <= uglys[i])  //watch out the overflow of int32
			{
				t2++;
			}

			while ((long long)uglys[t3] * 3 <= uglys[i])
			{
				t3++;
			}

			while ((long long)uglys[t5] * 5 <= uglys[i])
			{
				t5++;
			}
		}
	}

	bool isUgly(int num) {

		if (num <= 0)  //very important!!!
		{
			return false;
		}

 		while (num%2 == 0)
 		{
 			num = num / 2;
 		}
 
 		while (num % 3 == 0)
 		{
 			num = num / 3;
 		}
 
 		while (num % 5 == 0)
 		{
 			num = num / 5;
 		}
 
 		if (num == 1)
 		{
 			return true;
 		}
 		else
 		{
 			return false;
 		}


// 		for (int i = 0; i < 2000; i++)
// 		{
// 			if (uglys[i]==num)
// 			{
// 				return true;
// 			}
// 		}
// 
// 		return false;
	}

private:
	int uglys[2000];
};

int main()
{
	Solution s;
	if (s.isUgly(0))
	{
		cout << "Ugly";
	}
	return getchar();
}