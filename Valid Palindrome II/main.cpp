#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		for (int i = 0; i < s.size()/2; i++)
		{
			if (s[i] != s[s.size() - i - 1])
			{
				string tmp = s.substr(i + 1, s.size() - i - 1 - i);
				bool b1 = is_palindrome(tmp);

				string tmp2 = s.substr(i, s.size() - i - 1 - i);
				bool b2 = is_palindrome(tmp2);

				return b1 || b2;
			}
		}

		return true;
	}

	bool is_palindrome(string s) 
	{
		for (int i = 0; i < s.size()/2; i++)
		{
			if (s[i] != s[s.size()-i-1])
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
	s.validPalindrome("c");
	return getchar();
}