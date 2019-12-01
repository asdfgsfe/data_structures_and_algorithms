class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
		//dp[i][j]表示以i,j结尾的情况下组成的全为1的正方形数
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int cnt = 0;
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    continue;
                }
                dp[i][j] = (i == 0 || j == 0) ? 1 : std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};

//也可以用预处理数组o(n*n*n) 但是边界条件很麻烦 有时间了在调试下
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return 0;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> sums(m, vector<int>(n));
		sums[0][0] = matrix[0][0];
		for (int i = 1; i < sums[0].size(); ++i)
		{
			sums[0][i] = matrix[0][i] + sums[0][i - 1];
		}
		for (int i = 1; i < sums.size(); ++i)
		{
			sums[i][0] = matrix[i][0] + sums[i - 1][0];
		}
		for (int i = 1; i < sums.size(); ++i)
		{
			for (int j = 1; j < sums[0].size(); ++j)
			{
				sums[i][j] = matrix[i][j] + sums[i - 1][j] + sums[i][j - 1];
			}
		}
		Dump(sums);
		int cnt = 0;
		for (int size = 1; size <= std::min(n, m); ++size)
		{
			for (int i = 0; i < m - size; ++i)
			{
				for (int j = 0; j < n - size; ++j)
				{
					if (size == 1 && matrix[i][j] == 1)
					{
						cnt++;
					}
					else
					{
						int area = sums[i + size][j + size ] + sums[i][j] - sums[i + size][j] - sums[i][j + size];
						std::cout << "area=" << area << " size=" << size << std::endl;
						if (matrix[i][j] && matrix[i + size - 1][j] && matrix[i][j + size - 1] && matrix[i + size - 1][j + size - 1] && area == size * size)
						{
							++cnt;
						}
					}
				}
			}
		}
		return cnt;
	}
};


给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

 

示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释： 
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.
示例 2：

输入：matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。 
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.
 

提示：

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。