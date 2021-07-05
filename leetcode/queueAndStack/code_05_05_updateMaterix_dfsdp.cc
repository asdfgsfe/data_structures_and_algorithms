01 矩阵
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

 

示例 1：

输入：
[[0,0,0],
 [0,1,0],
 [0,0,0]]

输出：
[[0,0,0],
 [0,1,0],
 [0,0,0]]
示例 2：

输入：
[[0,0,0],
 [0,1,0],
 [1,1,1]]

输出：
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

提示：

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
相关标签
广度优先搜索
数组
动态规划
矩阵

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/g7pyt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//感觉是对的 但是不能通过
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return {};
        }
         vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> distance(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }
                distance[i][j] = UpdateProcess(mat, i, j, dp, visited);
            }
        }
        return distance;
    }

    int UpdateProcess(const vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp, vector<vector<int>>& visited) {
        if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size() || mat[r][c] == 0 || visited[r][c]) {
            return 0;
        }
        visited[r][c] = 1;
        if (dp[r][c] == 0) {
            int path = 0x7fffffff;
            path = std::min(path, UpdateProcess(mat, r - 1, c, dp, visited));
            path = std::min(path, UpdateProcess(mat, r + 1, c, dp, visited));
            path = std::min(path, UpdateProcess(mat, r, c - 1, dp, visited));
            path = std::min(path, UpdateProcess(mat, r, c + 1, dp, visited));
            dp[r][c] = 1 + path;
        }
        visited[r][c] = 0;
        return 1 + path;
    }
};
