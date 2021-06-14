零矩阵
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/ciekh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//时间n*n 空间n*n
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != 0 || visited[i][j]) {
                    continue;
                }
                visited[i][j] = 1;
                for (int k = 0; k < matrix.size(); ++k) {
                    if (matrix[k][j] != 0) {
                        visited[k][j] = 1;
                    }
                }
                for (int k = 0; k < matrix[0].size(); ++k) {
                    if (matrix[i][k] != 0) {
                        visited[i][k] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (visited[i][j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
