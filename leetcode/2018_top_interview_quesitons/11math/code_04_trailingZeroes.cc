class Solution {
public:
	int trailingZeroes(int n) {
		unsigned int nCount = 0;
		while (n) {
			nCount += (n / 5);
			n /= 5;
		}
		return nCount;
	}
};

//���ӣ�https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/q172-factorial-trailing-zeroes-by-ronhou/