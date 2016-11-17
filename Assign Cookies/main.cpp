
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
#include <vector>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int ret = 0;
		int i = 0;
		for (auto cookie : g)
		{
			while (i < s.size())
			{
				if (cookie <= s[i])
				{
					ret++; i++;
					break;;

				}
				i++;
			}
		}

		return ret;
	}
};
int main()
{
	Solution s;
	s.findContentChildren(vector<int>{1, 2}, vector<int>{1, 2, 3} );
	return getchar();
}

