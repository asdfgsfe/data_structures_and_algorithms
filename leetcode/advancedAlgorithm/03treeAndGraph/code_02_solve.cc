 class Solution {
 public:
	 void solve(vector<vector<char>>& board) {
		 if (board.empty() || board[0].empty())
		 {
			 return;
		 }
		 int r = board.size() - 1;
		 int c = board[0].size() - 1;
		 for (int i = 0; i <= r; ++i)
		 {
			 if (board[i][0] == 'O')
			 {
				 std::cout << "f1" << std::endl;
				 InfectProcess(board, i, 0);
			 }
		 }
		 for (int i = 0; i <= c; ++i)
		 {
			 if (board[0][i] == 'O')
			 {
				 std::cout << "f2" << std::endl;
				 InfectProcess(board, 0, i);
			 }
		 }
		 for (int i = 0; i <= r; ++i)
		 {
			 if (board[i][c] == 'O')
			 {
				 std::cout << "f3" << std::endl;
				 InfectProcess(board, i, c);
			 }
		 }
		 for (int i = 0; i <= c; ++i)
		 {
			 if (board[r][i] == 'O')
			 {
				 std::cout << "f4" << std::endl;
				 InfectProcess(board, r, i);
			 }
		 }
		 for (int i = 0; i <= r; ++i)
		 {
			 for (int j = 0; j <= c; ++j)
			 {
				 if (board[i][j] == 'A')
				 {
					 board[i][j] = 'O';
				 }
				 else if (board[i][j] == 'O')
				 {
					 board[i][j] = 'X';
				 }
			 }
		 }
	 }

	 void InfectProcess(vector<vector<char>>& board, int r, int c)
	 {
		 if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O')
		 {
			 return;
		 }
		 board[r][c] = 'A';
		 InfectProcess(board, r + 1, c);
		 InfectProcess(board, r - 1, c);
		 InfectProcess(board, r, c + 1);
		 InfectProcess(board, r, c - 1);
	 }
 };