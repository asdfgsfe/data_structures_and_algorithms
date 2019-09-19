 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
        {
            return 0;
        }
        return SumProcess(triangle, 0, 0);
    }
    
    int SumProcess(const vector<vector<int>>& triangle, int i, int j)
    {
        if (i == triangle.size() || j == triangle[i].size())
        {
            return 0;
        }
        return triangle[i][j] + std::min(SumProcess(triangle, i + 1, j), SumProcess(triangle, i + 1, j + 1));
    }
};


//perfect
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
        {
            return 0;
        }
        vector<int> dp = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};