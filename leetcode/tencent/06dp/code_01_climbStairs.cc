爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
        {
            return n;
        }
        int f1 = 1;
        int f2 = 2;
        int f3;
        for (int i = 3; i <= n; ++i)
        {
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return n;
        }
        int f0 = 1;
        int f1 = 1;
        int f2;
        for (int i = 2; i <= n; ++i) {
            f2 = f1 + f0;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};
