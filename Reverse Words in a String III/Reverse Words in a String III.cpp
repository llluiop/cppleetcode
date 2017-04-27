// Reverse Words in a String III.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int pre = 0;
		int next = 0;
		while ((next = s.find(' ', pre)) != string::npos)
		{
			reverse(s.begin() + pre, s.begin() + next);
			pre = next + 1;
		}

		reverse(s.begin() + pre, s.end());

		return s;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "Let\'s take LeetCode contest";
	Solution sln;

	sln.reverseWords(s);
	return 0;
}

