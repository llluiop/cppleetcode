class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> v;
		for (auto word : words)
		{
			if (word == "") continue;
			int row = map1[tolower(word[0])];

			bool can = true;
			for (auto c : word)
			{
				auto next = map1[tolower(c)];
				if (row != next)
				{
					can = false;
					break;
				}
			}

			if (can) v.push_back(word);
		}

		return v;
	}
	Solution()
	{
		map1['q'] = 1; map1['w'] = 1; map1['e'] = 1; map1['r'] = 1; map1['t'] = 1; map1['y'] = 1; map1['u'] = 1; map1['i'] = 1; map1['o'] = 1; map1['p'] = 1;
		map1['a'] = 2; map1['s'] = 2; map1['d'] = 2; map1['f'] = 2; map1['g'] = 2; map1['h'] = 2; map1['j'] = 2; map1['k'] = 2; map1['l'] = 2;
		map1['A'] = 2; map1['S'] = 2; map1['D'] = 2; map1['F'] = 2; map1['G'] = 2; map1['H'] = 2; map1['J'] = 2; map1['K'] = 2; map1['L'] = 2;
		map1['z'] = 3; map1['x'] = 3; map1['c'] = 3; map1['v'] = 3; map1['b'] = 3; map1['n'] = 3; map1['m'] = 3;
		map1['Z'] = 3; map1['X'] = 3; map1['C'] = 3; map1['V'] = 3; map1['B'] = 3; map1['N'] = 3; map1['M'] = 3;
	}

private:
	map<char, int> map1;
};