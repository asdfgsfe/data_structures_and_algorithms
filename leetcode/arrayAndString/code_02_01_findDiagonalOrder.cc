class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
		{
			return {};
		}
		int m = matrix.size() - 1;
		int n = matrix[0].size() - 1;
		int dR = 0;
		int dC = 0;
		int tR = 0;
		int tC = 0;
		bool fromUp = true;
		vector<int> nums;
		while (dR <= m && dC <= n)
		{
			//std::cout << dR << " " << dC << " " << tR << " " << tC << std::endl;
			PrintEdge(matrix, dR, dC, tR, tC, fromUp, nums);
			dC = dR == m ? dC + 1 : dC;
			dR = dR == m ? dR : dR + 1;
			tR = tC == n ? tR + 1 : tR;
			tC = tC == n ? tC : tC + 1;
			fromUp = !fromUp;
		}
		return nums;
	}

	void PrintEdge(const vector<vector<int>>& m, int dR, int dC, int tR, int tC, bool fromUp, vector<int>& nums)
	{
		if (fromUp)
		{
			while (dR >= tR && dC <= tC)
			{
				nums.emplace_back(m[dR--][dC++]);
			}
		}
		else
		{
			while (tR <= dR && tC >= dC)
			{
				nums.emplace_back(m[tR++][tC--]);
			}
		}
	}
};