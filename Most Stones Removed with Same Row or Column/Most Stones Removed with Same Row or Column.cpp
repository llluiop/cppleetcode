// Most Stones Removed with Same Row or Column.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	int* pre;
	int removeStones(vector<vector<int>> stones) {
		int len = stones.size();
		pre = new int[100000];
		for (int i = 0; i < 100000; i++) {
			pre[i] = i;
		}


		for (auto stone : stones) {
			un(stone[0], stone[1] + 10000);
		}

		set<int> s;
		for (auto stone : stones) {
			s.insert(find(stone[0]));
			cout << find(stone[0]);
		}


		return len - s.size();
	}

	void un(int x, int y) {
		int fx = find(x);
		int fy = find(y);

		if (fx != fy)
			pre[fx] = fy;
	}

	int find(int x) {
		while (pre[x] != x) {
			x = pre[x];
		}
		return x;
	}
};


int main()
{
	Solution s;
	s.removeStones({ {0,0} ,{0,2},{1,1},{2,0},{2,2} });
    std::cout << "Hello World!\n";
}


