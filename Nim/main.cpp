class Solution {
public:
	bool canWinNim(int n) {
		if (n % 4 == 0)
			return false;
		else
			return true;
	}
};


//At frist, we can win when our friend faces 4 of the left stones, so to make sure of it ,when we nim, the left of the stone has to be in range(5-7), 
//otherwise our friend can make it to 4, then we lose. In this case our friend has to face 8(whichever he takes, the stone of left is 5-7.
//we can also get 12, 16, 20, ... ,4*n , when the stone is 4*n, our friend can not win