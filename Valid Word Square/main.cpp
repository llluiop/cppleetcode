
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
	bool validWordSquare(vector<string> words)
	{
		int row = words.size();

		for (int i = 0; i < row; i++)
		{
			string word = words[i];
			for (int j = 0; j < word.size(); j++)
			{
				if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i])
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	s.validWordSquare(vector<string>({ "abcd",
		"bnrt",
		"crm",
		"dt" }));
	return getchar();
}

