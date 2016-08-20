#include <vector>


using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
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


class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (auto list : nestedList)
		{
			if (list.isInteger())
			{
				nextInt.push_back(list.getInteger());
			}
			else
			{
				auto tmp = list.getList();
				NestedIterator iter(tmp);
				while (iter.hasNext())
				{
					nextInt.push_back(iter.next());
				}
			}
		}

		cur = 0;
	}

	int next() {
		return nextInt[cur++];
	}

	bool hasNext() {
		if (cur >= nextInt.size())
		{
			return false;
		}

		return true;
	}

private:
	vector<int> nextInt;
	int cur;
};