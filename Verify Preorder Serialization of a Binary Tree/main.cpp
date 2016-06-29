#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder == "#")
		{
			return true;
		}

		stringstream s(preorder);
		char delimeterred[24] = {0};

		stack<int> treeNodes;
		queue<string> nodes;
		while (s.getline(delimeterred, 24, ','))
		{
			nodes.push(string(delimeterred));
		}

		while (!nodes.empty())
		{
			//string deli(delimeter);
			string deli = nodes.front();
			nodes.pop();

			if (!hashTag(deli))
			{
				treeNodes.push(0);
			}
			else
			{
				if (treeNodes.empty())
				{
					return false;
				}

				treeNodes.top()++;
				while (treeNodes.top() == 2)
				{
					treeNodes.pop();
					if (!treeNodes.empty())
						treeNodes.top()++;
					else if (!nodes.empty())
					{
						return false;
					}
					else
						break;
				}

			}
		}

		return treeNodes.empty();

	}

	inline bool hashTag(string c)
	{
		return c == "#";
	}
};

int main()
{
	Solution s;

	//cout << s.isValidSerialization("9,#,#,1");
	//cout << s.isValidSerialization("1");
	//cout << s.isValidSerialization("9,#,#");
	//cout << s.isValidSerialization("#");
	cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
	return getchar();
}
