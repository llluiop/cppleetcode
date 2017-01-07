
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;


class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		int len = s.length();
		vector<string> ret;
		if (len < 10)
		{
			return ret;
		}

		map<string, int> m;
		for (int i = 0; i <= len - 10; i++)
		{
			m[s.substr(i, 10)]++;
		}

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second > 1)
			{
				ret.push_back(iter->first);
			}
		}

		return ret;
	}
};


int main()
{
	Solution s;
	s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	return getchar();
}

