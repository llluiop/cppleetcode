
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

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		vector<double> ret;
		
		map<string, vector<string>> relations;
		map<string, double> results;

		for (int i = 0; i < equations.size(); i++)
		{
			auto equation = equations[i];
			auto value = values[i];

			relations[equation.first].push_back(equation.second);
			results[equation.first + ":" + equation.second] = value;
			if (value != 0)
			{
				relations[equation.second].push_back(equation.first);
				results[equation.second + ":" + equation.first] = 1 / value;
			}
		}

		for (auto query : queries)
		{
			ret.push_back(dfs(query, relations, results, set<string>{}));
		}

		return ret;
	}

	double dfs(pair<string, string>& query, map<string, vector<string>>& relations, map<string, double>& results, set<string> visited)
	{
		double ret = -1;
		visited.insert(query.first);

		if (relations.find(query.first) == relations.end())
		{
			visited.erase(query.first);
			return ret;
		}

		
		auto relation = relations[query.first];
		for (auto rel : relation)
		{
			if (rel == query.second)
			{
				ret = results[query.first + ":" + query.second];
				break;
			}
			else if (visited.find(rel) == visited.end())
			{
				double mid_ret = -1;
				mid_ret = dfs(pair<string, string>{ rel, query.second }, relations, results, visited);
				if (mid_ret != -1)
					ret = mid_ret * results[query.first + ":" + rel];
			}
		}

		visited.erase(query.first);
		return ret;
		
	}
};


int main()
{
	Solution s;
	s.calcEquation(vector<pair<string, string>>({ pair<string, string>{ "a", "b" }, pair<string, string>{ "b", "c" } }), vector<double>{2.0, 3.0},
		vector<pair<string, string>>{{"a", "c"}, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } });
	return getchar();
}

