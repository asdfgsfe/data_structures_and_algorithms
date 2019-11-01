�������� II
����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���

ʾ��:

����: 3
���:
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