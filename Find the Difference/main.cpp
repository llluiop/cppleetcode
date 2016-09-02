#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		map<char, int> m;
		for (auto c : s)
		{
			m[c]++;
		}

		for (auto c : t)
		{
			m[c]--;
		}

		auto iter = m.begin();
		while (iter != m.end())
		{
			if (iter->second == -1)
			{
				return iter->first;
			}
			++iter;
		}

		return ' ';
	}
};

int main()
{
	Solution s;
	cout<<s.findTheDifference("hello", "helloo");
	return getchar();
}