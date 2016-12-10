
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;

};



class Solution {
public:
	int DFS(const vector<NestedInteger>& nestedList, int depth)
	{
		int sum = 0;
		for (auto& nest : nestedList)
		{
			if (nest.isInteger())
			{
				sum += depth * nest.getInteger();
			}
			else
			{
				sum += DFS(nest.getList(), depth++);
			}
		}

		return sum;
	}

	int depthSum(vector<NestedInteger>& nestedList) {
		return DFS(nestedList, 1);
	}
};


int main()
{
	Solution s;	
	return getchar();
}

