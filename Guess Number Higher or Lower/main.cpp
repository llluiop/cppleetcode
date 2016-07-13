#include <vector>
#include <iostream>

// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
	if (num == 1702766719)
	{
		return 0;
	}
	else if (num  > 1702766719)
	{
		return -1;
	}
	else
		return 1;
}

class Solution {
public:
	int guessNumber(int n) {
		int low = 1;
		int high = n;

		while (low <= high)
		{
			int mid = (low+ ((high - low) / 2));

			int gus = guess(mid);
			if (gus == 0)
			{
				return mid;
			}
			else if (gus == 1)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}

		return 0;
	}
};

int main()
{
	Solution s;
	s.guessNumber(2126753390);
	return getchar();
}