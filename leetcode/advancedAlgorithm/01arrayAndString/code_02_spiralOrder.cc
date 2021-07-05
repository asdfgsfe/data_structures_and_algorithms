螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xw3ng2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        vector<int> order;
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while (tR <= dR && tC <= dC) {
            OrderEdge(matrix, tR++, tC++, dR--, dC--, order);
        }
        return order;
    }

    void OrderEdge(const vector<vector<int>>& matrix, int tR, int tC, int dR, int dC, vector<int>& order) {
        if (tR == dR) {
            while (tC <= dC) {
                order.emplace_back(matrix[tR][tC++]);
            }
            return;
        }
        if (tC == dC) {
            while (tR <= dR) {
                order.emplace_back(matrix[tR++][tC]);
            }
            return;
        }
        int r = tR;
        int c = tC;
        while (c < dC) {
            order.emplace_back(matrix[r][c++]);
        }
        while (r < dR) {
            order.emplace_back(matrix[r++][c]);
        }
        while (c > tC) {
            order.emplace_back(matrix[r][c--]);
        }
        while (r > tR) {
            order.emplace_back(matrix[r--][c]);
        }
    }
};
