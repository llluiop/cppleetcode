#include <vector>


using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() == 0)
		{
			return v;
		}

		//for (int i = 0; i < candidates.size(); i++)
		{
			vector<int> com;
			combination(candidates, target, com, 0);
		}

		return v;
	}

private:
	void combination(vector<int>& candidates, int target, vector<int> com, int index)
	{
		if (target < 0) return;

		if (target == 0)
		{
			v.push_back(com);
			return;
		}

		for (int i = index; i < candidates.size(); i++)
		{
			com.push_back(candidates[i]);
			combination(candidates, target - candidates[i], com, i);
			com.pop_back();
		}

	}
	
private:
	vector<vector<int>> v;
};


int main()
{
	Solution s;
	vector<int> candidates{ 2, 3, 6, 7 };
	s.combinationSum(candidates, 6);
	return getchar();
}