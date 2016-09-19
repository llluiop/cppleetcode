#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0) return;
		
		int row = board.size();
		int col = board[0].size();

		map<pair<int, int>, int> m;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				auto live_dead = neigborstate(i, j, row, col, board);
				state(i, j, live_dead, m, board);
			}
		}

		nextGeneration(m, board);
	}

	void state(int i, int j, tuple<int, int>& live_dead, map<pair<int, int>, int>& m, vector<vector<int>>& board)
	{
		if (board[i][j] == 1)
		{
			if (get<1>(live_dead) < 2 || get<1>(live_dead) > 3)
			{
				m[make_pair(i, j)] = 0;
			}
		}
		else
		{
			if (get<1>(live_dead) == 3)
			{
				m[make_pair(i, j)] = 1;
			}
		}
	}

	void nextGeneration(map<pair<int, int>, int>& m, vector<vector<int>>& board)
	{
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			board[iter->first.first][iter->first.second] = iter->second;
		}
	}

	tuple<int, int> neigborstate(int i, int j, int row, int col, vector<vector<int>>& board)
	{
		int dead_num = 0;
		int live_num = 0;

		dead_num += dead(i - 1, j - 1, row, col, board);
		dead_num += dead(i, j - 1, row, col, board);
		dead_num += dead(i + 1, j - 1, row, col, board);
		dead_num += dead(i + 1, j, row, col, board);
		dead_num += dead(i + 1, j + 1, row, col, board);
		dead_num += dead(i, j + 1, row, col, board);
		dead_num += dead(i - 1, j + 1, row, col, board);
		dead_num += dead(i - 1, j, row, col, board);

		live_num += live(i - 1, j - 1, row, col, board);
		live_num += live(i, j - 1, row, col, board);
		live_num += live(i + 1, j - 1, row, col, board);
		live_num += live(i + 1, j, row, col, board);
		live_num += live(i + 1, j + 1, row, col, board);
		live_num += live(i, j + 1, row, col, board);
		live_num += live(i - 1, j + 1, row, col, board);
		live_num += live(i - 1, j, row, col, board);

		return std::make_pair(dead_num, live_num);
	}

	bool dead(int i, int j, int row, int col, vector<vector<int>>& board)
	{
		if (i >= 0 && i < row && j >= 0 && j < col)
		{
			return board[i][j] == 0;
		}

		return false;
	}

	bool live(int i, int j, int row, int col, vector<vector<int>>& board)
	{
		if (i >= 0 && i < row && j >= 0 && j < col)
		{
			return board[i][j] == 1;
		}

		return false;
	}
};

int main()
{
	Solution s;
	s.gameOfLife(vector<vector<int>>{});
	return getchar();
}