// Reshape the Matrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.size() == 0)
		{
			return nums;
		}

		int row = nums.size();
		int col = nums[0].size();

		if (row * col != r * c)
		{
			return nums;
		}

		vector<vector<int>> ret;
		ret.resize(r);
		for (auto& v : ret)
		{
			v.resize(c);
		}

		int new_row = 0;
		int new_col = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ret[new_row][new_col] = nums[i][j];
				++new_col;
				if (new_col == c)
				{
					new_col = 0;
					++new_row;
				}
			}
		}

		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<vector<int>> v{ { 1, 2 }, { 3, 4 } };

	s.matrixReshape(v, 1, 4);
	return 0;
}

