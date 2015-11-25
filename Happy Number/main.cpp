#include <iostream>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0)
		{
			return false;
		}

		int sum = n;
		while (sum >= 10)
		{
			sum = digitalsum(sum);
		}

		// we will find only 1 and 7 is happy num when n < 10, 
		// others will go into an endless loop, as we know the n will less than 10 eventually 
		// by adding the squares of all its digits.
		if (sum == 1 || sum == 7) 									
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	inline int digitalsum(int n)
	{
		int sum = 0;
		while (n != 0)
		{
			int lowerset = n % 10;
			sum += lowerset*lowerset;
			n = n / 10;
		}

		return sum;
	}
};


int main()
{
	Solution s;
	cout << s.isHappy(7);
	return getchar();
}