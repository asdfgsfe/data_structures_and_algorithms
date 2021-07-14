class Solution {
public:
    double myPow(double x, int n) {
        bool minus = n < 0 ? true : false;
        double ret = PowProcess(x, std::labs(n));
        return minus ? 1 / ret : ret;
    }

    double PowProcess(double x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        double ret = PowProcess(x, n / 2);
        ret = n % 2 != 0 ? ret * ret * x : ret * ret;
        return ret;
    }
};

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
相关标签
递归
数学


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xwo102/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
