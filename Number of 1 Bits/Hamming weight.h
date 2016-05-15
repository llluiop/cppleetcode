class Solution {
public:
	int hammingWeight(unsigned int n) {
		int w = 0;
		while (n != 0)
		{
#if 0
			w += (n & 1);
			n = (n >> 1);
#endif
			w++;
			n = n&(n - 1); //move the last 1 in binary
		}

		return w;
	}
};