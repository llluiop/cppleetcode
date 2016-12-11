// Reverse String II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		string ret;
		int i = 0;
		while (i + k <= s.size())
		{
			auto tmp = s.substr(i, k);
			reverse(tmp.begin(), tmp.end());

			ret += tmp;

			int left = min(k, (int)s.size() - i - k);
			tmp = s.substr(i + k, left);
			ret += tmp;

			i = i + 2 * k;
		}

		if (i < s.size())
		{
			auto tmp = s.substr(i, s.size() - i);
			reverse(tmp.begin(), tmp.end());
			ret += tmp;
		}

		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.reverseStr("abcdefg", 2);
	return 0;
}

