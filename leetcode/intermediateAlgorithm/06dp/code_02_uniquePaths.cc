class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][n - 1] = 1;
        }
        for (int i = 0; i < dp[0].size(); ++i) {
            dp[m - 1][i] = 1;
        }
        for (int i = dp.size() - 2; i >= 0; --i) {
            for (int j = dp[0].size() - 2; j >= 0; --j) {
                dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};

62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
