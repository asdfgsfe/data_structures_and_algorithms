void ZigZagPrintMatrix(const vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return;
	}
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	int rE = matrix.size() - 1;
	int cE = matrix.front().size() - 1;
	bool fromUp = true;
	while (tR <= rE && tC <= cE)
	{
		PrintEdge(matrix, tR, tC, dR, dC, fromUp);
		dR = dC == cE ? dR + 1 : dR;
		dC = dC == cE ? dc : dc + 1;
		tC = tR == rE ? tC + 1 : tC;
		tR = tR == rE ? tR : tR + 1;
		fromUp = !fromUp;
	}
}

void PrintEdge(const vector<int>& matrix, int tR, int tC, int dR, int dC, bool fromUp)
{
	if (fromUp)
	{
		while (tR >= dR)
		{
			std::cout << matrix[tR--][tC++] << " ";
		}
	}
	else
	{
		while (tR >= dR)
		{
			std::cout << matrix[dR++][dC--] << " ";
		}
	}
	std::cout << std::endl;
}