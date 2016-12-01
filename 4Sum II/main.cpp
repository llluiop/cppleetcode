
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <map>
#include <bitset>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		map<int, int> v1;
		for (auto a : A)
		{
			for (auto b : B)
			{
				v1[(a + b)]++;
			}
		}

		int ret = 0;
		for (auto c: C)
		{
			for (auto d : D)
			{
				if (v1.find(-c - d) != v1.end()) ret += v1[-c-d];
			}
		}


		return ret;
	}
};


int main()
{
	Solution s;
	//s.fourSumCount(vector<int>({ 3, 10, 5, 25, 2, 8 }));
	return getchar();
}

