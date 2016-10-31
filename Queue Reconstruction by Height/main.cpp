#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		vector<pair<int, int>> v;
		sort(people.begin(), people.end(), [&](pair<int, int> p1, pair<int, int> p2){return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second; });

		for (auto person : people)
		{
			v.insert(v.begin() + person.second, person);
		}

		return v;
	}
};

int main()
{
	Solution s;
	s.reconstructQueue(vector<pair<int,int>>{ { 1,2 } });
	return getchar();
}