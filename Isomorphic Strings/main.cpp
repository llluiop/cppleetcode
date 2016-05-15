#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		for (int i = 0; i < s.size(); i++)
		{
			char c1 = s[i];
			char c2 = t[i];


			if (m_.find(c1) == m_.end())
			{
				for (auto iter : m_)
				{
					if (m_[iter.first] == c2)
					{
						return false;
					}
				}
				m_[c1] = c2;
			}
			else
			{
				if (m_[c1] != c2)
				{
					return false;
				}
			}

		}

		return true;
	}


private:
	map<char, char> m_;
};


int main()
{
	Solution s;
	s.isIsomorphic("baa", "cfa");
	return getchar();
}