// Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		if (s == "") return s;

		int max_len = 1;
		int lo = 0;
		for (size_t i = 0; i < s.length()-1; i++)
		{
			int left = i - 1;
			int right = i + 1;

			while (left  >= 0 && right < s.length())
			{
				if (s[left] != s[right])
					break;

				left--;
				right++;
			}

			if (max_len < right - left - 1)
			{
				max_len = right - left - 1;
				lo = left + 1;
			}

			left = i;
			right = i + 1;
			while (left >= 0 && right < s.length())
			{
				if (s[left] != s[right])
					break;

				left--;
				right++;
			}

			if (max_len < right - left - 1)
			{
				max_len = right - left - 1;
				lo = left + 1;
			}

		}
		auto ss = s.substr(lo, max_len);
		return ss;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.longestPalindrome("cbbd");
	return 0;
}

