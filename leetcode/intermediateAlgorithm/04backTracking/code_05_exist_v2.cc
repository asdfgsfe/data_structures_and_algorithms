单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvkwe2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && ExistProcess(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool ExistProcess(const vector<vector<char>>& board, int r, int c, const string& word, int p, vector<vector<bool>>& visited) {
        if (p == word.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || word[p] != board[r][c]) {
            return false;
        }
        visited[r][c] = true;
        bool ret = ExistProcess(board, r + 1, c, word, p + 1, visited);
        ret |= ExistProcess(board, r - 1, c, word, p + 1, visited);
        ret |= ExistProcess(board, r, c + 1, word, p + 1, visited);
        ret |= ExistProcess(board, r, c - 1, word, p + 1, visited);
        visited[r][c] = false;
        return ret;
    }
};
