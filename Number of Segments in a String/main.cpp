
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
	int countSegments(string s) {		
		int start = 0;
		int count = 0;

		while (start < s.length())
		{
			int c = next_character(s, start);
			if (c == s.length())
			{
				break;
			}

			count++;
			start = next_space(s, c);
		}

		return count;
	}

	int next_character(string s, int start)
	{
		while (start < s.length() && s[start] == ' ')
		{
			start++;
		}

		return start;
	}

	int next_space(string s, int start)
	{
		while (start < s.length() && s[start] != ' ')
		{
			start++;
		}

		return start;
	}
};


int main()
{
	Solution s;
	s.countSegments(", , , ,    sdfdf, asdfdsf  ");
	return getchar();
}

