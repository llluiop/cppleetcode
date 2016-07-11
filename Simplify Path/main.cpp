#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		stringstream ss(path);

		string partial = "";
		while (getline(ss, partial, '/'))
		{
			if (partial == "." || partial == "")
			{
				continue;
			}
			if (partial == "..")
			{
				if (!st.empty())
				{
					st.pop();
				}
			}
			else
			{
				st.push(partial);
			}
		}


		string ret = "";
		while (!st.empty())
		{
			ret = "/" + st.top() + ret;
			st.pop();
		}

		return ret == ""?"/":ret;
	}
};


int main()
{
	Solution s;

	s.simplifyPath("/abc/...");
	return getchar();
}