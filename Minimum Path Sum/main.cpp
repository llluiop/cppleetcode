#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//int minPathSum(vector<vector<int>>& grid) {
	//	if (grid.size() == 0)
	//	{
	//		return 0;
	//	}

	//	row_ = grid.size();
	//	col_ = grid[0].size();

	//	min_ = INT_MAX;

	//	if (row_ == 1 && col_ == 1)
	//	{
	//		min_ = grid[0][0];
	//	}

	//	v_.resize(row_);
	//	for (auto& v : v_)
	//	{
	//		v.resize(col_, INT_MAX);
	//	}

	//	sumPath(grid, 0, 0, 0);



	//	return min_;
	//}

	//void sumPath(vector<vector<int>>& grid, int row, int col, int total)
	//{
	//	total += grid[row][col];

	//	if (total > v_[row][col]) //add cache
	//	{
	//		return;
	//	}

	//	v_[row][col] = total;

	//	if (total > min_)
	//	{
	//		return;
	//	}

	//	if (row == row_ - 1 && col == col_ - 1)
	//	{	
	//		min_ = total;
	//		return;
	//	}

	//	if (row + 1 < row_)
	//	{
	//		sumPath(grid, row + 1, col, total);
	//	}
	//	
	//	if (col + 1 < col_)
	//	{
	//		sumPath(grid, row, col + 1, total);
	//	}
	//	
	//}


	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
		{
			return 0;
		}

		row_ = grid.size();
		col_ = grid[0].size();

		v_.resize(row_);
		for (auto& v : v_)
		{
			v.resize(col_, INT_MAX);
		}

		return sumPath(grid, row_-1, col_-1);
	}

	int sumPath(vector<vector<int>>& grid, int row, int col)
	{
		if (row == 0 && col == 0)
		{
			return grid[row][col];
		}

		if (row < 0 || col < 0)
		{
			return INT_MAX;
		}

		if (v_[row][col] != INT_MAX)
		{
			return v_[row][col];
		}

		v_[row][col] = std::min(sumPath(grid, row - 1, col), sumPath(grid, row, col - 1)) + grid[row][col];

		return  v_[row][col];
	}

private:
	int col_;
	int row_;
	int min_;

	vector<vector<int>> v_;
};

int main()
{
	Solution s;

	vector<vector<int>> v = { { 7, 1, 3, 5, 8, 9, 9, 2, 1, 9, 0, 8, 3, 1, 6, 6, 9, 5 }, { 9, 5, 9, 4, 0, 4, 8, 8, 9, 5, 7, 3, 6, 6, 6, 9, 1, 6 }, { 8, 2, 9, 1, 3, 1, 9, 7, 2, 5, 3, 1, 2, 4, 8, 2, 8, 8 }, { 6, 7, 9, 8, 4, 8, 3, 0, 4, 0, 9, 6, 6, 0, 0, 5, 1, 4 }, { 7, 1, 3, 1, 8, 8, 3, 1, 2, 1, 5, 0, 2, 1, 9, 1, 1, 4 }, { 9, 5, 4, 3, 5, 6, 1, 3, 6, 4, 9, 7, 0, 8, 0, 3, 9, 9 }, { 1, 4, 2, 5, 8, 7, 7, 0, 0, 7, 1, 2, 1, 2, 7, 7, 7, 4 }, { 3, 9, 7, 9, 5, 8, 9, 5, 6, 9, 8, 8, 0, 1, 4, 2, 8, 2 }, { 1, 5, 2, 2, 2, 5, 6, 3, 9, 3, 1, 7, 9, 6, 8, 6, 8, 3 }, { 5, 7, 8, 3, 8, 8, 3, 9, 9, 8, 1, 9, 2, 5, 4, 7, 7, 7 }, { 2, 3, 2, 4, 8, 5, 1, 7, 2, 9, 5, 2, 4, 2, 9, 2, 8, 7 }, { 0, 1, 6, 1, 1, 0, 0, 6, 5, 4, 3, 4, 3, 7, 9, 6, 1, 9 } };
	cout << s.minPathSum(v);

	return getchar();
}