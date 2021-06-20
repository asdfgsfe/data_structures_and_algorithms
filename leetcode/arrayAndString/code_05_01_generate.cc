杨辉三角
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
相关标签
数组

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/cuj3m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) {
            return {};
        }
        vector<vector<int>> matrix(numRows);
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> tmp(i + 1, 1);
            for (int j = 1; j < tmp.size() - 1; ++j) {
                tmp[j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
            }
            matrix[i] = std::move(tmp);
        }
        return matrix;
    }
};
