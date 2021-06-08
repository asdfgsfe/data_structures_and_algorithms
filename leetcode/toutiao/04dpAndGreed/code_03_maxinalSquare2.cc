//域处理数组 只不过利用sum来做的 看着就是别人的答案
//在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

//利用累加和判断内部全部是1
//和在一个数组中计算某一段累加和是一样 从i～j的累加和等于 dp[j] - dp[i] dp[i]表示从0—i的累加和
这道题让我们求一个二维区域和的检索，是之前那道题Range Sum Query - Immutable 区域和检索的延伸。
有了之前那道题的基础，我们知道这道题其实也是换汤不换药，还是要建立一个累计区域和的数组，
然后根据边界值的加减法来快速求出给定区域之和。这里我们维护一个二维数组dp，
其中dp[i][j]表示累计区间(0, 0)到(i, j)这个矩形区间所有的数字之和，
那么此时如果我们想要快速求出(r1, c1)到(r2, c2)的矩形区间时，
只需dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]即可，
下面的代码中我们由于用了辅助列和辅助行，所以下标会有些变化，参见代码如下：
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) 
	{
        if (matrix.empty() || matrix[0].empty()) return;
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
    
private:
    vector<vector<int> > dp;
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
        {
            return 0;
        }
        int m = matrix.size(); 
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = 0; j < matrix[i].size(); ++j) 
            {
                int t = matrix[i][j] - '0';
                if (i > 0) 
                {
                    t += sum[i - 1][j];
                }
                if (j > 0)
                {
                    t += sum[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    t -= sum[i - 1][j - 1];
                }
                sum[i][j] = t;
                int cnt = 1;
                for (int k = min(i, j); k >= 0; --k) 
                {
                    int d = sum[i][j];
                    if (i - cnt >= 0) d -= sum[i - cnt][j];
                    if (j - cnt >= 0) d -= sum[i][j - cnt];
                    if (i - cnt >= 0 && j - cnt >= 0) d += sum[i - cnt][j - cnt];
                    if (d == cnt * cnt) res = max(res, d);
                    ++cnt;
                }
            }
        }
        return res;
    }
};
