螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return {};
        }
        vector<int> order(matrix.size() * matrix[0].size());
        int p = 0;
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while (tR <= dR && tC <= dC)
        {
            OrderEdge(order, p, matrix, tR++, tC++, dR--, dC--);
        }
        return order;
    }
    
    void OrderEdge(vector<int>& order, int& p, const vector<vector<int>>& m, int tR, int tC, int dR, int dC)
    {
        int r = tR;
        int c = tC;
        if (tR == dR)
        {
            while (c <= dC)
            {
                order[p++] = m[r][c++];
            }
        }
        else if (tC == dC)
        {
            while (r <= dR)
            {
                order[p++] = m[r++][c];
            }
        }
        else
        {
            while (c < dC)
            {
                order[p++] = m[r][c++];
            }
            while (r < dR)
            {
                order[p++] = m[r++][c];
            }
            while (c > tC)
            {
                order[p++] = m[r][c--];
            }
            while (r > tR)
            {
                order[p++] = m[r--][c];
            }
        }
    }
};