#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> v;

		if (matrix.size() == 0)
		{
			return v;
		}

		int row = matrix.size();
		int col = matrix[0].size();

		for (int i = 0, j = 0; 0 < row && 0 < col; i++, j++)
		{
			for (int m = 0; m < col; m++)
			{
				v.push_back(matrix[i][j + m]);
			}

			for (int m = 1; m < row; m++)
			{
				v.push_back(matrix[i + m][matrix[0].size() -i - 1]);
			}

			for (int m = 1; m < col && row != 1; m++)
			{
				v.push_back(matrix[matrix.size() - i - 1][matrix[0].size() - m - j- 1]);
			}

			for (int m = 1; m < row - 1 && col != 1; m++)
			{
				v.push_back(matrix[matrix.size() - i - 1- m][j]);
			}

			col -= 2;
			row -= 2;
		}

		return v;
	}
};


int main()
{
	Solution s;

	//vector<vector<int>> v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 },{ 17, 18, 19, 20 } };
	//vector<vector<int>> v = { { 1, 2, 3, 4 } };
	//vector<vector<int>> v = { { 1 } };
	vector<vector<int>> v = { { 1 }, { 2 }, { 3 } };

	s.spiralOrder(v);

	return getchar();
}