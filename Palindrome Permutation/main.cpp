
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

bool canPermutePalindrome(string s) {
	map<char, int> m;
	for (auto c : s)
	{
		m[c]++;
	}

	int odd = 0;
	for (auto c : m)
	{
		if (c.second % 2 != 0)
		{
			odd++;
			if (odd == 1)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	
	return getchar();
}

