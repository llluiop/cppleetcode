#include <string>
#include <map>
using namespace std;
#include <sstream>

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		istringstream istr(str);


		string word = "";
		int i = 0;
		for (; i < pattern.size(); i++)
		{
			if (!(istr >> word))
				return false;

			if (m_.find(pattern[i]) != m_.end())
			{

				if (word != m_[pattern[i]])
				{
					return false;
				}
			}
			else
			{
				for (auto iter : m_)
				{
					if (m_[iter.first] == word)
					{
						return false;
					}
				}
				m_[pattern[i]] = word;
			}
		}

		return  !(istr>>word);
	}

private:
	map<char, string> m_;
};



int main()
{
	Solution s;
	s.wordPattern("abba", "dog cat cat dog");
	return getchar();
}