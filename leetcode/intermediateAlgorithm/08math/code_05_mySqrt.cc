class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x / 2;
        int t;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((long long)m * m <= (long long)x) {
                t = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return t;
    }
};

69. x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。
