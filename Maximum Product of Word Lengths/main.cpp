#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#define max(a, b)  (((a) > (b)) ? (a) : (b))
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.size() <= 1)
			return 0;

		int res = 0;

		vector<int> mask(words.size(), 0);
		for (int i = 0; i < words.size(); i++)
		{
			for (char c: words[i])
			{
				mask[i] |= 1 << (c - 'a');
			}

			for (int j = 0; j < i; j++)
			{
				if (!(mask[i] & mask[j]))
				{
					res = max(res, int(words[i].length() * words[j].length()));
				}
			}
		}

		return res;
	}
};

int main()
{
	vector<string> v = {};

	Solution s;
	cout << s.maxProduct(v);
	return getchar();
}