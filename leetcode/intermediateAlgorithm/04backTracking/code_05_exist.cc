class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
        {
            return true;
        }
        if (board.empty() || board[0].empty())
        {
            return false;
        }
		//这个地方很重要 必须移到for外面 不然超时
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0] && ExistProcess(board, i, j, word, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool ExistProcess(const vector<vector<char>>& board, int i, int j, const string& word, int p, vector<vector<bool>>& visited)
    {
        if (p == word.size())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[p])
        {
            return false;
        }
        visited[i][j] = true;
        if (ExistProcess(board, i - 1, j, word, p + 1, visited))
        {
            return true;
        }
        if (ExistProcess(board, i + 1, j, word, p + 1, visited))
        {
            return true;
        }
        if (ExistProcess(board, i, j - 1, word, p + 1, visited))
        {
            return true;
        }
        bool found = ExistProcess(board, i, j + 1, word, p + 1, visited);
        visited[i][j] = false;
        return found;
    }
};