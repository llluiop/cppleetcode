#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	enum CKIND
	{
		NONE,
		UPPER,
		LOWER,
		NUM,
	};

	bool isPalindrome(string s) {
		if (s == "")
		{
			return true;
		}

		string tmp = "";
		for (auto c : s)
		{
			if (isCharacter(c) == LOWER || isCharacter(c) == NUM)
			{
				tmp += c;
			}
			else if (isCharacter(c) == UPPER)
			{
				tmp += tolower(c);
			}
		}

		int i = 0;
		int j = tmp.length() - 1;

		while (i < j)
		{
			if (tmp[i] != tmp[j])
			{
				return false;
			}

			i++;
			j--;
		}

		return true;
	}

private:
	CKIND isCharacter(char c)
	{
		if (c >= 'a' && c <= 'z')
		{
			return LOWER;
		}

		if (c >= 'A' && c <= 'Z')
		{
			return UPPER;
		}

		if (c >= '0' && c <= '9')
		{
			return NUM;
		}

		return NONE;
	}

	char toLower(char c)
	{
		return c - 'A' + 'a';
	}
};


int main()
{
	Solution s;
	s.isPalindrome("0P");
	return getchar();
}