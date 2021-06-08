class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxEdge = 0;
        //以(i,j)为左下脚定点的时候 所能组成的最大面积 答案必然在其中
        //(i, j)=0 那他的面积必然为0
        //(i, j)=1, 他的面积来自于 (i - 1, j), (i, j-1),(i-1,j-1)的最小值+1
        //只能是最小值 因为要组成全1的正方形 最小的才是3者的交集
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if (matrix[i][j] == '1')
                {
                    dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                maxEdge = std::max(maxEdge, dp[i][j]);
            }
        }
        return maxEdge * maxEdge;
    }
};
