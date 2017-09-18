#include "../include/stdc++.h"

#include "../include/stdc++.h"

class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0;
		int y = 0;
		for (auto c : moves)
		{
			if (c == 'L')
			{
				x--;
			}
			else if (c == 'R')
			{
				x++;
			}
			else if (c == 'U')
			{
				y++;
			}
			else
			{
				y--;
			}
		}

		return x == 0 && y == 0;
	}
};

int main() {
	Solution s;
	s.judgeCircle("");
	return 0;
}