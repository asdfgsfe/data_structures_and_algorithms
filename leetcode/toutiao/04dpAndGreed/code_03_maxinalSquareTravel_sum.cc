//域处理数据的技术 仅仅只是改变了判断是否为全1正方行的方法
//利用求sum的方法 代码比使用right down矩阵方法简单
//对于矩阵 数组的题目想到域处理技术 sum方法和累加方法
//o(n * n * n)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        vector<vector<int>> sums(matrix.size(), vector<int>(matrix[0].size(), 0));
        sums[0][0] = matrix[0][0] - '0';
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix.size(); ++j)
            {
                sums[i][j] = matrix[i][j] - '0' + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
        for (int size = std::min(matrix.size(), matrix[0].size()); size > 0; --size)
        {
            for (int i = 0; i <= matrix.size() - size; ++i)
            {
                for (int j = 0; j <= matrix[0].size() - size; ++j)
                {
                    int area = sums[i + size - 1][j + size - 1] - sums[i + size - 1][j] - sums[i][j + size - 1] + sums[i][j];
                    if (area == (size - 1)* (size-1))
                    {
                        return area;
                    }
                }
            }
        }
        return 0;
    }
};
