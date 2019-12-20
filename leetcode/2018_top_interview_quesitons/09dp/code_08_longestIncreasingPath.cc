 class Solution {
 public:
	 int longestIncreasingPath(vector<vector<int>>& matrix) {
		 if (matrix.empty() || matrix[0].empty())
		 {
			 return 0;
		 }
		 int longgest = 0;
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