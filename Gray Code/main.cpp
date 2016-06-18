#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> v(1, 0);


		for (int i = 1; i <= n; i++)
		{
			vector<int> cur(v.begin(), v.end());
			for (int j = v.size()-1; j >= 0; j--)
			{
				cur.push_back(v[j] | 1<<(i-1));
			}
			
			v.swap(cur);
		}

		return v;
	}
};

int main()
{
	Solution s;

	s.grayCode(3);

	return getchar();
}