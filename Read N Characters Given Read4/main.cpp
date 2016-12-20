
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
	int read(char *buf, int n)
	{
		if (buf == nullptr)
		{
			return 0;
		}

		int sum = 0;

		int ret = 0;
		int start = 0;

		char tmp[4];
		while (ret = read4(tmp) > 0 && n >= 0)
		{
			for (int i = 0; i < min(ret, n); i++)
			{
				buf[start++] = tmp[i];
			}

			n -= ret;
			sum += ret;
		}
		
		return sum;
	}

	int read4(char* buf){ return 4; }
};

int main()
{
	Solution s;
	return getchar();
}

