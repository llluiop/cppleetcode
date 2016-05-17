#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0)
		{
			return vector<string>();
		}

		vector<string> v;
		generate(v, "", n, 0);
		return v;
	}

private:
	void generate(vector<string>& v, string s, int n, int left)
	{
		if (left < n)
		{
			generate(v, s + "(", n, left + 1);
		}

		if (left > s.size() - left)
		{
			generate(v, s + ")", n, left);
		}

		if (s.size() == n*2)
		{
			v.push_back(s);
		}
	}
};


int main()
{
	Solution s;
	s.generateParenthesis(3);
	return getchar();
}