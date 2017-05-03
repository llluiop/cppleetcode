// Longest Uncommon Subsequence I.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b) return -1;

		return max(a.size(), b.size());
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

