螺旋矩阵 II
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n < 2)
		{
			return { { 1 } };
		}
		vector<vector<int>> matrix(n, vector<int>(n));
		int tR = 0;
		int tC = 0;
		int dR = n - 1;
		int dC = n - 1;
		int s = 1;
		while (tR <= dR && tC <= dC)
		{
			FullEdge(s, matrix, tR++, tC++, dR--, dC--);
		}
		return matrix;
	}

	void FullEdge(int& s, vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
	{
		int r = tR;
		int c = tC;
		if (tR == dR)
		{
			assert(tC == dC);
			matrix[r][c] = s++;
		}
		else
		{
			while (c < dC)
			{
				matrix[r][c++] = s++;
			}
			while (r < dR)
			{
				matrix[r++][c] = s++;
			}
			while (c > tC)
			{
				matrix[r][c--] = s++;
			}
			while (r > tR)
			{
				matrix[r--][c] = s++;
			}
		}
	}
};