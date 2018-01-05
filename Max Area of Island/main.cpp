#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:


	int max_area = 0;
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;
		vector<vector<int>> visited(grid);

		int col = grid[0].size();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int now = get(grid, i, j, row, col, visited);
				max_area = max(max_area, now);


			}
		}

		return max_area;

	}

	int get(vector<vector<int>>& grid, int i, int j, int row, int col, vector<vector<int>>& visited)
	{

		if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0)
		{
			return 0;
		}

		if (visited[i][j] == 2)
			return 0;

		

		visited[i][j] = 2;
		


		return 	1+get(grid, i - 1, j, row, col, visited)
				+get(grid, i + 1, j, row, col, visited)
			    +get(grid, i, j - 1, row, col, visited)
		        +get(grid, i, j + 1, row, col, visited);


	}

};

int main()
{
	Solution s;
	s.maxAreaOfIsland(vector<vector<int>>{ {1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1} });
	return getchar();
}