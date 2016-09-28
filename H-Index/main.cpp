#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int size = citations.size();
		if (size == 0)
		{
			return 0;
		}

		sort(citations.begin(), citations.end());

		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (citations[i] >= size - i)
			{
				index = max(index, size - i);
			}
		}

		return index;
	}
};

int main()
{
	Solution s;
	cout << s.hIndex(vector<int>{ 1, 2, 3, 3, 5 });
	return getchar();
}