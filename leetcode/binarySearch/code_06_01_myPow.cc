Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

 

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/binary-search/xe7k32/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0)
        {
            return 0.0;
        }
		//这里很重要 而不能使用abs(n)
        long long exp = (long long)n;
        double ret = PowProcess(x, exp < 0 ? -exp : exp);
        return n < 0 ? 1 / ret : ret;
    }
    
    double PowProcess(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        bool odd = (n & 0x01) == 0x01;
        double half = PowProcess(x, n / 2);
        half *= half;
        half = odd ? half * x : half;
        return half;
    }
};
