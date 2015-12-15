#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		if (secret.size() == 0)
		{
			return "0A0B";
		}

		vector<char> sec;
		vector<char> gue;

		int bull = 0;
		int cows = 0;

		for (int i = 0; i < secret.size(); i++)
		{
			if (secret[i] == guess[i])
			{
				bull++;
			}
			else
			{
				sec.push_back(secret[i]);
				gue.push_back(guess[i]);
			}				
		}

		sort(sec.begin(), sec.end());
		sort(gue.begin(), gue.end());

		vector<char> v(secret.size());
		auto it = set_intersection(sec.begin(), sec.end(), gue.begin(), gue.end(), v.begin());

		cows = it - v.begin();

		stringstream str;
		str << bull;
		str << "A";
		str << cows;
		str << "B";
		return str.str();
	}
};


int main()
{
	Solution s;
	string secret = "1807";
	string guess = "7810";

	cout << s.getHint(secret, guess);
	return getchar();
}