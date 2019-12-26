class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
        {
            return 0;
        }
		//nlog(n)
        vector<bool> isPrimes(n, true);
        for (int i = 2; i * i < n; ++i)
        {
            if (isPrimes[i])
            {
				//如果一个数是素数 那么他的倍数必然不为素数
				//i* i之前的数字 一定会被前面标记 所以从i*i开始
                for (int j = i * i; j < n; j += i)
                {
                    isPrimes[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < isPrimes.size(); ++i)
        {
            if (isPrimes[i])
            {
                ++cnt;
            }
        }
        return cnt;
    }
};

//质数就是素数  一个数除了1和他本身外不能被其他数整除 就是素数
//如果一个数是素数 那么他的倍数必然不为素数
//参考答案
//链接：https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/