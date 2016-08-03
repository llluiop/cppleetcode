#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();

		vector<pair<int, int>> v0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 0)
				{
					v0.emplace_back(i, j);
				}
			}
		}

		for (auto p : v0)
		{
			for (int i = 0; i < col; i++)
			{
				matrix[p.first][i] = 0;
			}

			for (int i = 0; i < row; i++)
			{
				matrix[i][p.second] = 0;
			}
		}
	}
};

int main()
{
	Solution s;
	s.setZeroes(vector<vector<int>>{ { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 0 } });
	return getchar();
}