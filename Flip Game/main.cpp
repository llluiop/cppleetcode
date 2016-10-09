
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

vector<string> generatePossibleNextMoves(string s) {
	vector<string> v;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == '+' && s[i+1] == '+')
		{
			string tmp = s;
			tmp[i] = '-'; tmp[i + 1] = '-';
			v.push_back(tmp);
		}
	}

	return v;
}

int main()
{

	return getchar();
}

