 class Solution {
 public:
	 int longestIncreasingPath(vector<vector<int>>& matrix) {
		 if (matrix.empty() || matrix[0].empty())
		 {
			 return 0;
		 }
		 int longgest = 0;
         //不需要visited 因为有递增这个条件的限制 所以不会走到原来的位置
         vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		 for (int i = 0; i < matrix.size(); ++i)
		 {
			 for (int j = 0; j < matrix[0].size(); ++j)
			 {
				 longgest = std::max(longgest, IncreaseProcess(matrix, i, j, 0x80000000, dp));
			 }
		 }
		 return longgest;
	 }

	 int IncreaseProcess(const vector<vector<int>>& m, int r, int c, int pre, vector<vector<int>>& dp)
	 {
		 if (r < 0 || r >= m.size() || c < 0 || c >= m[0].size() || m[r][c] <= pre)
		 {
			//注意：因为输入的时候空构造了1个数子，所以返回0
             return 0;
		 }
         if (dp[r][c] == 0)
         {
		    dp[r][c] = IncreaseProcess(m, r + 1, c, m[r][c], dp) + 1;
		    dp[r][c] = std::max(dp[r][c], IncreaseProcess(m, r, c + 1, m[r][c], dp) + 1);
		    dp[r][c] = std::max(dp[r][c], IncreaseProcess(m, r - 1, c, m[r][c], dp) + 1);
		    dp[r][c] = std::max(dp[r][c], IncreaseProcess(m, r, c - 1, m[r][c], dp) + 1);
         }
		 return dp[r][c];
	 }
 };



329. 矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。



示例 1：


输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4
解释：最长递增路径为 [1, 2, 6, 9]。
示例 2：


输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
示例 3：

输入：matrix = [[1]]
输出：1


提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

