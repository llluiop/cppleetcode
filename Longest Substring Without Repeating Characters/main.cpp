#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0;

		int index = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = index; j < i; j++)
			{
				if (s[i] == s[j])
				{
					index = j+1;
				}
			}

			ret = max(ret, i - index+1);
		}

		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("ynyo");
	return getchar();
}