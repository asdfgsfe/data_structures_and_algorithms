class Solution {
public:
    int numSquares(int n) {
        if (n < 1) {
            return 0;
        }
        //dfs+dp 如果这个数组已经计算过了 就不用在计算了
        unordered_map<int, int> dp;
        return SquareProcess(n, dp);
    }

    int SquareProcess(int n, unordered_map<int, int>& dp) {
        if (n == 0) {
            return 0;
        }
        auto it = dp.find(n);
        if (it != dp.end()) {
            return it->second;
        }
        int cnt = 0x7fffffff;
        for (int i = sqrt(n); i > 0; --i) {
            cnt = std::min(cnt, SquareProcess(n - i * i, dp));
        }
        dp[n] = 1 + cnt;
        return 1 + cnt;
    }
};


完全平方数
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

 

示例 1：

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
示例 2：

输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：

1 <= n <= 104
相关标签
广度优先搜索
数学
动态规划

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xd03l1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
