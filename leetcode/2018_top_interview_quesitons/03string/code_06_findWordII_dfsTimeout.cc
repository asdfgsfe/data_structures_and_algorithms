 class Solution {
 public:
	 vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		 if (board.empty())
		 {
			 return {};
		 }
		 vector<string> existed;
		 for (const string& word : words)
		 {
			 if (IsExist(word, board))
			 {
				 existed.emplace_back(word);
			 }
		 }
		 return existed;
	 }

	 bool IsExist(const string& word, const vector<vector<char>>& board)
	 {
		 if (word.empty() || board.empty() || board[0].empty())
		 {
			 return false;
		 }
		 for (int i = 0; i < board.size(); ++i)
		 {
			 for (int j = 0; j < board[0].size(); ++j)
			 {
				 if (board[i][j] == word[0])
				 {
					 vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
					 if (ExistProcess(word, 0, board, i, j, visited))
					 {
						 return true;
					 }
				 }
			 }
		 }
		 return false;
	 }

	 bool ExistProcess(const string& word, int i, const vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited)
	 {
		 if (i == word.size())
		 {
			 return true;
		 }
		 if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] != word[i])
		 {
			 return false;
		 }
		 visited[r][c] = true;
		 bool found = ExistProcess(word, i + 1, board, r + 1, c, visited)
			 || ExistProcess(word, i + 1, board, r, c + 1, visited)
			 || ExistProcess(word, i + 1, board, r - 1, c, visited)
			 || ExistProcess(word, i + 1, board, r, c - 1, visited);
         visited[r][c] = false;
         return found;
     }
};