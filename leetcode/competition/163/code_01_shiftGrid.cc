//给你一个 n 行 m 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
//
//每次「迁移」操作将会引发下述活动：
//
//位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
//位于 grid[i][m - 1] 的元素将会移动到 grid[i + 1][0]。
//位于 grid[n - 1][m - 1] 的元素将会移动到 grid[0][0]。
//请你返回 k 次迁移操作后最终得到的 二维网格。

//输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//输出：[[9,1,2],[3,4,5],[6,7,8]]
//示例 2：
//输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
//输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
//示例 3：
//
//输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
//输出：[[1,2,3],[4,5,6],[7,8,9]]
// 
//
//提示：
//
//1 <= grid.length <= 50
//1 <= grid[i].length <= 50
//-1000 <= grid[i][j] <= 1000
//0 <= k <= 100

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty() || k < 1)
        {
            return grid;
        }
        int n = grid.size();
        int m = grid[0].size();
        while (k--)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (i == n - 1 && j == m - 1)
                    {
                        continue;
                    }
                    if (j == m - 1 && i + 1 != n)
                    {
                        std::swap(grid[0][0], grid[i + 1][0]);
                    }
                    else if (j != m - 1)
                    {
                        std::swap(grid[0][0], grid[i][j + 1]);
                    }
                }
            }
        }
        return grid;
    }
};