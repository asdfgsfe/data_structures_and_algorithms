class Solution {
public:
	int kthGrammar(int N, int K) {
        if (N == 1) 
		{
			return 0;
		}
		int ret = kthGrammar(N-1, (K+1)/2);
        return ret == 0 ? 1 - K % 2 : K % 2;
    }
};
//据此可以总结出规律，第 K 个数字是上一行第 (K+1) / 2 个数字生成的。
//如果上一行的数字为 0，被生成的数字为 1 - (K%2)，如果上一行的数字为 1，被生成的数字为 K%2。
//k%2为0表示上个数字生成的右孩子 位1为左孩子 1-(k%2)才是想要的答案
