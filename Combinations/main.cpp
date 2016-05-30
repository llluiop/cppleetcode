#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (n < k)
			return v;

		//for (size_t i = 1; i < n; i++)
		{
			vector<int> com;
			combine_(n, k, 1, com);
		}

		return v;
	}

private:
	void combine_(int n, int k, int index, vector<int>& com)
	{
		if (k == 0 )
		{
			v.push_back(com);
			return;
		}
		
		for (int i = index; i <= n; i++)
		{
			com.push_back(i);
			combine_(n, k - 1, i + 1, com);
			com.pop_back();
		}


	}
	vector<vector<int>> v;
};

int main()
{
	Solution s;


	s.combine(4, 3);

	return getchar();
}