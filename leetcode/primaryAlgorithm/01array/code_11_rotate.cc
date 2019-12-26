class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty() || matrix.size() != matrix[0].size())
        {
			return;
        }
		int tR = 0;
		int tC = 0;
		int dR = matrix.size() - 1;
		int dC = matrix[0].size() - 1;
		while (tC <= dC)
		{
			RotateEdge(matrix, tR++, tC++, dR--, dC--);
		}
    }

	void RotateEdge(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC)
	{
		if (tR < 0 || tR >= matrix.size() || tC < 0 || tC >= matrix[0].size())
		{
			return;
		}
        while (tC < dC)
        {
		    std::swap(matrix[tR][tC], matrix[tC][dC]);
		    std::swap(matrix[tR][tC], matrix[dC][dR]);
		    std::swap(matrix[tR][tC++], matrix[dR--][tR]);
        }
	}
};