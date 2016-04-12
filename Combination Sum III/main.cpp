#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> v;

		for (int i = 1; i <= 9; i++)
		{
			vector<int> vElem;
			vElem.push_back(i);
			combination(i, k-1, n-i, vElem, v);
			vElem.pop_back();
		}

		return move(v);
	}

private:
	void combination(int i, int k, int n, vector<int>& v1, vector<vector<int>>& v2)
	{
		if (k < 0 || n < 0)
		{
			return;
		}

		if (k == 0 && n == 0)
		{
			v2.push_back(v1);
			return;
		}


		for (int j = i+1; j <= 9; j++)
		{
			v1.push_back(j);
			combination(j, k - 1, n - j, v1, v2);
			v1.pop_back();
		}
	}

};


int main()
{
	Solution s;
	auto v = s.combinationSum3(3,9);

	for (auto v1 : v)
	{
		for (auto v11 : v1)
		{
			cout << v11 << " ";
		}
		cout << endl;
	}
	return getchar();
}