class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9 && board[0].size() != 9)
		{
			return false;
		}
		int tR = 0;
		int tC = 0;
		for (int i = 0; i < 9; ++i)
		{
			unordered_set<char> visited;
			for (int r = tR; r < tR + 3; ++r)
			{
				for (int c = tC; c < tC + 3; ++c)
				{
					if (board[r][c] == '.')
                    {
                        continue;
                    }
                    if (visited.count(board[r][c]))
					{
						return false;
					}
					visited.emplace(board[r][c]);
					for (int k = 0; k < 9; ++k)
					{
						if (k != r && board[k][c] == board[r][c])
						{
							return false;
						}
					}
					for (int k = 0; k < 9; ++k)
					{
						if (k != c && board[r][k] == board[r][c])
						{
							return false;
						}
					}
				}
			}
			tR = tC == 6 ? tR + 3 : tR;
			tC = tC == 6 ? 0 : tC + 3;
		}
		return true;
	}
};