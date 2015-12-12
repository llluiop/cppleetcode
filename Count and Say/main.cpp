#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		stringstream str;
		string now = "1";

		while (n > 0)
		{
			str.str("");
			char pre = now[0];
			int consant = 0;


			for (int i = 0; i <= now.size(); i++)
			{
				if (now[i] == pre)
				{
					consant++;
				}
				else
				{
					str << consant;
					str << pre;

					consant = 1;
					pre = now[i];
				}
			}

			now = str.str();
			--n;
		}

		return str.str();
	}
};


int main()
{
	string sss = "11";
	int i = sss.size();
	char c = sss[2];

	Solution s;

	cout << s.countAndSay(5);
	return getchar();
}