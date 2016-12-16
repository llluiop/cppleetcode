
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
	bool isStrobogrammatic(string num) {
		int i = 0; 
		int j = num.size() - 1;
		while (i <= j)
		{
			if (!couplematci(num[i], num[j]))
			{
				return false;
			}
			++i; --j;
		}

		return  true;
	}



	bool couplematci(char c1, char c2)
	{
		return (c1 == '0' && c2 == '0')
			|| (c1 == '1' && c2 == '1')
			|| (c1 == '8' && c2 == '8')
			|| (c1 == '6' && c2 == '9')
			|| (c1 == '9' && c2 == '6');
	}
};

int main()
{
	Solution s;
	s.isStrobogrammatic("689");
	return getchar();
}

