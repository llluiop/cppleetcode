
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
#include <vector>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.size() == 0)
		{
			return 0;
		}
		int row = grid.size();
		int col = grid[0].size();

		int ret = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ret += lines(i, j, grid, row, col);
			}
		}

		return ret;
	}

	int lines(int i, int j, vector<vector<int>>& grid, int row ,int col)
	{
		if (grid[i][j] == 0)
		{
			return 0;
		}

		int line = 0;
		if (i - 1 < 0)
		{
			line++;
		}
		else if (grid[i - 1][j] == 0)
		{
			line++;
		}

		if (j - 1 < 0)
		{
			line++;
		}
		else if (grid[i][j-1] == 0)
		{
			line++;
		}


		if (i + 1 >= row)
		{
			line++;
		}
		else if (grid[i + 1][j] == 0)
		{
			line++;
		}

		if (j + 1 >= col)
		{
			line++;
		}
		else if (grid[i][j+1] == 0)
		{
			line++;
		}
		return line;
	}
};


int main()
{
	Solution s;
	s.islandPerimeter(vector<vector<int>>{{{1, 1, 1, 1},
	{ 1, 1, 1, 1 },
	{ 1, 1, 1, 1 },
	{ 1, 1, 1, 0 }}});
	return getchar();
}

