#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())
			return false;

		map<char, int> m;
		for (auto c : s1)
			m[c]++;

		for (int i = 0; i <= s2.size() - s1.size(); i++)
		{
			map<char, int> mm;
			for (int j = 0; j < s1.size(); j++)
				mm[s2[i + j]]++;

			if (m == mm) return true;
		}
		return false;
	}
};


int main()
{
	Solution s;
	s.checkInclusion( "ab","eidbaooo");
	return getchar();
}