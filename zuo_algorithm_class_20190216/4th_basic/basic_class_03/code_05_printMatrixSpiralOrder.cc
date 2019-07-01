vodi PrintMatrixSpiralOrder(const vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return;
	}
	int x1 = 0;
	int y1 = 0;
	int x2 = matrix.size() - 1;
	int y2 = matrix.front().size() - 1;
	while (x1 <= x2 && y1 <= y2)
	{
		PrintEdge(matrix, x1++, y1++, x2--, y2--);
	}
}

void PrintEdge(const vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		while (y1 <= y2)
		{
			std::cout << matrix[x1][y1++] << " ";
		}
		std::cout << std::endl;
		return;
	}
	if (y1 == y2)
	{
		while (x1 <= x2)
		{
			std::cout << matrix[x1++][y2] << " ";
		}
		std::cout << std::endl;
		return;
	}
	int x = x1;
	int y = y1;
	while (y < y2)
	{
		std::cout << matrix[x][y++] << " ";
	}
	while (x < x2)
	{
		std::cout << matrix[x++][y] << " ";
	}
	while (y > y1)
	{
		std::cout << matrix[x][y--] << " ";
	}
	while (x > x1)
	{
		std::cout << matrix[x--][y] << " ";
	}
	std::cout << std::endl;
}