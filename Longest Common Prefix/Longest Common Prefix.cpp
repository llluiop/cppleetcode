#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
		{
			return "";
		}

		vector<int> v(strs[0].size(), 1);

		for (int i = 1; i < strs.size(); i++)
		{
			for (int j = 0; j < strs[i].size(); j++)
			{
				if (j >= strs[0].size())
				{
					break;
				}

				if (strs[i][j] == strs[0][j])
				{
					v[j]++;
				}
			}
		}

		int count = 0;
		for (int i : v)
		{
			if (i == strs.size())
			{
				count++;
			}
			else
			{
				break;
			}
		}

		return strs[0].substr(0, count);
	}
};


int main()
{
	Solution s;
	vector<string> v = { "h1i11", "hi2", "hi1" };

	cout << s.longestCommonPrefix(v);
	return getchar();
}