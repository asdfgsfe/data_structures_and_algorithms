//221. 最大正方形
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4


//域处理数据的技巧 但是时间复杂度浪费在查找全是1里面 
//适合只查找边界全是1的情况 按照right down的方法只能记录了边界全部为1的请求
//那么这个正方型的内部是不是1 没法知道
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> right(rows, vector<int>(cols, 0));
        right[rows - 1][cols - 1] = matrix.back().back() == '1' ? 1 : 0;
        vector<vector<int>> down(right);
        for (int i = rows - 2; i >= 0; --i)
        {
            if (matrix[i][cols - 1] == '1')
            {
                right[i][cols - 1] = 1;
                down[i][cols - 1] = 1 + down[i + 1][cols - 1];
            }
        }
        for (int i = cols - 2; i >= 0; --i)
        {
            if (matrix[rows - 1][i] == '1')
            {
                down[rows - 1][i] = 1;
                right[rows - 1][i] = 1 + right[rows - 1][i + 1];
            }
        }
        for (int i = rows - 2; i >= 0; --i)
        {
            for (int j = cols - 2; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    right[i][j] = 1 + right[i][j + 1];
                    down[i][j] = 1 + down[i + 1][j];
                }
            }
        }
        for (int size = std::min(rows, cols); size > 0; --size)
        {
            if (HasTheSize(right, down, size))
            {
                return size * size;
            }
        }
        return 0;
    }
    
    bool HasTheSize(const vector<vector<int>>& right, 
                    const vector<vector<int>>& down, 
                    int size)
    {
        int rows = right.size();
        int cols = right[0].size();
        for (int i = 0; i < rows - size + 1; ++i)
        {
            for (int j = 0; j < cols - size + 1; ++j)
            {
                int r = i;
                int c = j;
                int len = size;
                //由于没法知道内部是不是全部为1 所有便利去找每个边
                while (len > 0)
                {
                    if (right[r][c] < len || down[r][c] < len || right[r + len - 1][c] < len || down[r][c + len - 1] < len)
                    {
                        break;
                    }
                    ++r;
                    ++c;
                    --len;
                }
                if (len == 0)
                    return true;
            }
        }
        return false;
    }
};
