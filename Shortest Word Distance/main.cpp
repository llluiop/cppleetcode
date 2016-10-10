
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

int shortestDistance(vector<string> words, string word1, string word2) {
	int idx1 = -1;
	int idx2 = -1;

	int res = -1;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == word1)
		{
			idx1 = i;
		}
		else if (words[i] == word2)
		{
			idx2 = i;
		}

		if (idx1 != -1 && idx2 != -1)
			res = min(res, abs(idx1 - idx2));
	}

	return res;
}

int main()
{
	return getchar();
}

