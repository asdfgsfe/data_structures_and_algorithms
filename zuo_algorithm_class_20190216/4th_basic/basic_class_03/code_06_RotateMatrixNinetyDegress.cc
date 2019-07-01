void RotateMatrixNinetyDegrees(const vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix.front().empty() || matrix.size() != matrix.front().size())
	{
		return;
	}
	int x1 = 0;
	int y2 = 0;
	int x2 = matrix.size() - 1;
	int y2 = matrix.front().size() - 1;
	while (x1 <= x2 && y1 <= y2)
	{
		RotateEdge(matrix, x1++, y1++, x2--, y2--);
	}
}

//由于x1 == y1 x2 == y2正方形 利用横纵坐标互相交换搞定
void RotateEdge(const vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
{
	while (x1 < x2)
	{
		std::swap(matrix[x1][y1], matrix[y1][y2]);
		std::swap(matrix[x1][y1], matrix[y2][x2]);
		std::swap(matrix[x1][y1++], matrix[x2--][x1]);
	}
}

int main(void)
{	
	vector<vector<int>> matrix = {{1,2,3},
								  {4, 5, 6},
								  {7, 8, 9}};
	RotateMatrixNinetyDegrees(matrix);

	return 0;
}