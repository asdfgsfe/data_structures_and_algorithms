单词搜索 II
给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

 

示例 1：


输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
输出：["eat","oath"]
示例 2：


输入：board = [["a","b"],["c","d"]], words = ["abcb"]
输出：[]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同
相关标签
字典树
数组
字符串
回溯
矩阵


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdpw1v/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//超时了 dfs +	回溯
//只能用前缀树了
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty()) {
            return {};
        }
        unordered_set<string> exists;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (const string& w : words) {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (w[0] == board[i][j] && IsExists(board, i, j, w, 0, visited)) {
                        exists.emplace(w);
                    }
                }
            }
        }
        return vector<string>(exists.begin(), exists.end());
    }

    bool IsExists(const vector<vector<char>>& board, int r, int c, const string& w, int p, vector<vector<bool>>& visited) {
        if (p == w.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] != w[p]) {
            return false;
        }
        visited[r][c] = true;
        bool ret = IsExists(board, r + 1, c, w, p + 1, visited);
        ret |= IsExists(board, r - 1, c, w, p + 1, visited);
        ret |= IsExists(board, r, c + 1, w, p + 1, visited);
        ret |= IsExists(board, r, c - 1, w, p + 1, visited);
        visited[r][c] = false;
        return ret;
    }
};
