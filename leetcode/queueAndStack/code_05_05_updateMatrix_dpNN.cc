//方法 3：动态规划
//想法
//对于一个节点来说，它到 0 的距离可以通过邻居的最近距离计算，在这种情况下最近距离是邻居的距离 + 1。
//因此，这就让我们想到了动态规划！
//对于每个 1，到 0 的最短路径可能从任意方向。所以我们需要检查所有 4 个方向。
//在从上到下的迭代中，我们需要检查左边和上方的最短路径；我们还需要另一个从下往上的循环，检查右边和下方的方向。
//算法
//从上至下、从左至右迭代整个矩阵：
//更新
//dist[i][j]=min(dist[i][j],min(dist[i][j−1],dist[i−1][j])+1)
//最近距离考虑上方邻居和左侧邻居距离 + 1，这在前面的迭代中已经计算完成。
//从下到上、从右至左迭代整个矩阵：
//更新
//dist[i][j]=min(dist[i][j],min(dist[i][j+1],dist[i+1][j])+1)
//最近距离考虑下方邻居和右侧邻居距离 + 1，这在前面的迭代中已经计算完成。

//NOTICE
//掌握这种分两步从四个方向更新dp的方法

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return {};
		}
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0x7fffffff - 10000));
		for (int i = 0; i < dp.size(); ++i)
		{
			for (int j = 0; j < dp[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					dp[i][j] = 0;
					continue;
				}
				if (i > 0)
				{
					dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
				}
				if (j > 0)
				{
					dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
				}
			}
		}
		for (int i = dp.size() - 1; i >= 0; --i)
		{
			for (int j = dp[0].size() - 1; j >= 0; --j)
			{
				if (i < dp.size() - 1)
				{
					dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + 1);
				}
				if (j < dp[0].size() - 1)
				{
					dp[i][j] = std::min(dp[i][j], dp[i][j + 1] + 1);
				}
			}
		}
		return dp;
	}
};