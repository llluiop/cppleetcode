#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (auto& v : board)
		{
			if (!isValid(v))
			{
				return false;
			}
		}

		for (int i = 0; i < board.size(); i ++)
		{
			vector<char> c;
			for (int j = 0; j < board.size(); j++)
			{
				c.push_back(board[j][i]);
			}

			if (!isValid(c))
				return false;
		}

		for (int i = 0; i < board.size(); i += board.size() / 3)
		{

			for (int j = 0; j < board.size(); j += board.size() / 3)
			{
				vector<char> c;
				c.push_back(board[i][j]);
				c.push_back(board[i+1][j]);
				c.push_back(board[i+2][j]);

				c.push_back(board[i][j+1]);
				c.push_back(board[i + 1][j+1]);
				c.push_back(board[i + 2][j+1]);

				c.push_back(board[i][j+2]);
				c.push_back(board[i + 1][j+2]);
				c.push_back(board[i + 2][j+2]);

				if (!isValid(c))
					return false;
			}


		}

		return true;
	}

private:
	bool isValid(vector<char>& v)
	{
		bitset<9> b;
		for (auto& c : v)
		{
			if (c != '.')
			{
				if (b[c - '1'] == 1)
					return false;

				b[c - '1'] = 1;
			}
		}

		return true;
	}
};
int main()
{
	vector<vector<char>> v = { { '.', '.', '.', '.', '5', '.', '.', '1', '.'},
	{ '.', '4', '.', '3', '.', '.', '.', '.', '.'},
	{ '.', '.', '.', '.', '.', '3', '.', '.', '1'},
	{ '8', '.', '.', '.', '.', '.', '.', '2', '.'},
	{ '.', '.', '2', '.', '7', '.', '.', '.', '.'},
	{ '.', '1', '5', '.', '.', '.', '.', '.', '.'},
	{ '.', '.', '.', '.', '.', '2', '.', '.', '.'},
	{ '.', '2', '.', '9', '.', '.', '.', '.', '.'},
	{ '.', '.', '4', '.', '.', '.', '.', '.', '.'} };
	Solution s;
	cout << s.isValidSudoku(v);
	return getchar();
}