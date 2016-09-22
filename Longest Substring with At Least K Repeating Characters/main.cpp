#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.size() == 0 || k > s.size())   return 0;
		if (k == 0)  return s.size();

		int a[26] = { 0 };
		for (auto c : s)
		{
			a[c - 'a']++;
		}

		int i = 0;
		for (i = 0; i < s.size(); i++)
		{
			if (a[s[i] - 'a'] < k)
			{
				break;
			}
		}

		if (i == s.size())
		{
			return s.size();
		}

		int left = longestSubstring(s.substr(0, i), k);
		int right = longestSubstring(s.substr(i+1), k);

		return max(left, right);
	}
};


int main()
{
	Solution s;
	s.longestSubstring("ababaab", 3);
	return getchar();
}