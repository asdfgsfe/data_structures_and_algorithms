矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

 

示例 1：


输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。
示例 2：


输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
示例 3：

输入：matrix = [[1]]
输出：1
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
相关标签
深度优先搜索
广度优先搜索
图
拓扑排序
记忆化搜索
动态规划

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xde3ji/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int longest = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                longest = std::max(longest, Increase(matrix, i, j, 0x80000000, dp));
            }
        }
        return longest;
    }

    int Increase(const vector<vector<int>>& matrix, int r, int c, int pre, vector<vector<int>>& dp) {
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= pre) {
            return 0;
        }
        if (dp[r][c] == 0) {
			//注意这里要用 dp[r][c] 不然答案不正确
            dp[r][c] = 1 + Increase(matrix, r + 1, c, matrix[r][c], dp);
            dp[r][c] = std::max(dp[r][c], 1 + Increase(matrix, r - 1, c, matrix[r][c], dp));
            dp[r][c] = std::max(dp[r][c], 1 + Increase(matrix, r, c - 1, matrix[r][c], dp));
            dp[r][c] = std::max(dp[r][c], 1 + Increase(matrix, r, c + 1, matrix[r][c], dp));
        }
        return dp[r][c];
    }
};
