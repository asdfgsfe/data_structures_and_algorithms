旋转矩阵
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/clpgd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty() || matrix.size() != matrix[0].size()) {
            return;
        }
        int tR = 0;
        int tC = 0;
        int dR = matrix.size() - 1;
        int dC = matrix[0].size() - 1;
        while (tR <= dR && tC <= dC) {
            RotateEdge(matrix, tR++, tC++, dR--, dC--);
        }
    }

    void RotateEdge(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC) {
		//固定住一个位置 保证所有的c变化， r保持 然后分析如何组合
        while (tC < dR) {
            std::swap(matrix[tR][tC], matrix[tC][dR]);
            std::swap(matrix[tR][tC], matrix[dR][dC]);
            std::swap(matrix[tR][tC], matrix[dC][tR]);
            --dC;
            ++tC;
        }
    }
};
