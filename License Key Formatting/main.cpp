
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;



class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string ret = "";

		int need_dash = 0;
		for (int i = S.size() - 1; i >= 0; i--)
		{
			if (S[i] == '-') continue;

			ret += MakeUpper(S[i]);
			need_dash++;

			if (need_dash == K)
			{
				ret += '-';
				need_dash = 0;
			}
		}

		if (ret == "") return ret;


		if (ret[ret.size()-1] == '-')
		{
			ret.erase(ret.end() - 1);
		}
		reverse(ret.begin(), ret.end());

		return ret;
	}

	char MakeUpper(char c)
	{
		if (c >= 'a' && c <= 'z')
		{
			return c + ('A' - 'a');
		}

		return c;
	}
};


int main()
{
	Solution s;
	s.licenseKeyFormatting("2-4A0r7-4k", 4);
	return getchar();
}

