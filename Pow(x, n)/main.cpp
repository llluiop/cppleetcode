#include <iostream>


using namespace std;

#define MIN_VALUE DBL_EPSILON  //根据需要调整这个值
#define IS_DOUBLE_ZERO(d) (abs(d) < MIN_VALUE) 
#define IS_DOUBLE_1(d) (abs((abs(d)-1)) < MIN_VALUE) 


class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
		{
			return 1;
		}

		if (n == INT_MIN)
		{
			return 0;
		}
		if (IS_DOUBLE_1(x))
		{
			return (x<0 && n%2!= 0)?-1:1;
		}

		bool negtive = (n < 0);
		n = abs(n);

		double result = x;
		while (n-- > 1)
		{
			result *= x;
			if (abs(result) > std::numeric_limits<double>::max())
			{
				break;
			}

			if (abs(result) < std::numeric_limits<double>::min())
			{
				break;
			}
		}

		if (negtive)
		{
			result = 1 / result;
		}

		return result;
	}
};

int main()
{
	Solution s;

	auto v = s.myPow(2.00000, INT_MIN);

	return getchar();
}