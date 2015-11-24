#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0 || n == 1)
		{
			return 1;
		}

/*		return climbStairs(n - 1) + climbStairs(n - 2);*/  //time exceeded

		//fibonacci
		int f1 = 1, f2 = 1;
		while (n >= 2)
		{	
			int tmp = f2;
			f2 = f1 + f2;
			f1 = tmp;

			--n;
		}

		return f2;
	}
};


int main()
{
	Solution s;
	cout << s.climbStairs(3) << ' ' << s.climbStairs(1) << ' ' << s.climbStairs(2);
	return getchar();
}