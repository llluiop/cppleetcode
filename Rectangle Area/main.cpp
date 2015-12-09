#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		/*if (E >= C || A >= G || B >= H || F >= D)
		{
			return 0;
		}
		//how stupid you are!!!
		if (E >= A && F >= B && C >= G && D >= H)
		{
			return (G - E)*(H - F);
		}

		if (E <= A && F <= B && C <= G && D <= H)
		{
			return (C - A)*(D - B);
		}

		if (inRect(A, B, E, F, G, H))
		{
			return (G - A)*(H - B);
		}

		if (inRect(C, D, E, F, G, H))
		{
			return (C - E)*(D - F);
		}

		if (inRect(A, D, E, F, G, H))
		{
			return (G - A)*(D - F);
		}

		if (inRect(C, B, E, F, G, H))
		{
			return (C - E)*(H - B);
		}*/

		//elegant!!!
		int res = (D - B) * (C - A) + (H - F) * (G - E);
		int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H);
		if (D1 <= B1 || C1 <= A1) return res;
		return res - (D1 - B1) * (C1 - A1);
	}

private:
	int min(int a, int b)
	{
		return a > b ? b : a;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	bool inRect(int a, int b, int r1, int r2, int r3, int r4)
	{
		if (a > r1 && a < r3 && b >r2 && b < r4)
		{
			return true;
		}

		return false;
	}
};

int main()
{

	Solution s;
	cout << s.computeArea(0,0,0,0,-1,-1,1,1);
	return getchar();
}