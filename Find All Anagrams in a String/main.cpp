#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> v;
		if (s == "" | p == "")
		{
			return v;
		}

		if (s.length() < p.length())
		{
			return v;

		}

		int pLen = p.length();
		for (int i = 0; i <= s.length()-pLen; i++)
		{
			if (cmp(s, i, p))
				v.push_back(i);
		}

		return v;
	}

	bool cmp(string s, int start, string p)
	{
		int len = p.length();

		int a[26] = { 0 };
		int b[26] = { 0 };

		for (int i = 0; i < len; i++)
		{
			a[s[i + start] - 'a']++;
			b[p[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++)
		{
			if (a[i] != b[i])
			{
				return false;
			}
		}
		return true;
	}
};


int main()
{
	Solution s;
	s.findAnagrams("cbaebabacd", "abc");
	return getchar();
}