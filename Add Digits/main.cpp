class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};
  /*Given N: N = a[n]*10^n + a[n-1]*10^(n-1)+...+a[0]
  1《1(mod 9)
  10《1(mod 9)
  100《1(mod 9)
	...

  a[0]+a[1]*10+´+a[n]*10^n《(a[0]+a[1]+´+a[n])(mod 9)

  N《M(mod 9) ;M=a[n]+a[n-1]+...+a[0]

  */

int main()
{
	Solution s;
	s.addDigits(18);
	return 0;
}