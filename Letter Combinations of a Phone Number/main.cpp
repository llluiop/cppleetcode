#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits == "")
		{
			return{};
		}

		vector<string> s;
		string combination = "";

		combinations(0, digits, combination, s);

		return s;
	}

private:
	void combinations(int index, string digits, string combination, vector<string>& s)
	{
		if (index == digits.length())
		{
			s.push_back(combination);
		}
		else
		{
			auto letter = map2str(digits[index]);
			for (char c : letter)
			{
				combinations(index + 1, digits, combination + c, s);
			}
		}
	}
	string map2str(char c)
	{
		switch (c)
		{
		case '2':
			return "abc";
		case '3':
			return "def";
		case '4':
			return "ghi";
		case '5':
			return "jkl";
		case '6':
			return "mno";
		case '7':
			return "pqrs";
		case '8':
			return "tuv";
		case '9':
			return "wxyz";

		default:
			break;
		}

		return "";
	}
};
int main()
{
	Solution trie;
	trie.letterCombinations("23");


	return getchar();
}