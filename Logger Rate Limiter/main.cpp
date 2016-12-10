
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <unordered_map>
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



class Logger {
public:
	Logger() {}

	bool shouldPrintMessage(int timestamp, string message) {
		if (m.find(message) != m.end())
		{
			m[message] = timestamp;
			return true;
		}
		else
		{
			auto last_time = m[message];
		
			if (timestamp - last_time <= 10)
			{
				return false;
			}
			else
			{
				m[message] = timestamp;
				return true;
			}
		}
	}

private:
	unordered_map<string, int> m;
};


int main()
{
	Logger s;
	return getchar();
}

