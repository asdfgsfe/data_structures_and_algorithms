class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty()) {
            return {};
        }
        vector<string> ansWords;
		//不一样的地方在于这里用了回溯策略， 全局只需要申请一个visited空间
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (const string& word : words) {
            if (word.empty()) {
                continue;
            }
            bool found = false;
            for (int r = 0; r < board.size(); ++r) {
                for (int c = 0; c < board[0].size(); ++c) {
                    if (board[r][c] == word[0]) {
                        found = findProcess(word, 0, visited, board, r, c);
                        if (found) {
                            ansWords.emplace_back(word);
                            break;
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
        }
        return ansWords;
    }

    bool findProcess(const string& word, int i, vector<vector<bool>>& visited,
					const vector<vector<char>>& board, int r, int c) {
        if (i == word.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || word[i] != board[r][c]) {
            //这个地方正常应该是要回溯的
			// if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && visited[r][c]) {
            //     visited[r][c] = false;
            // }
            return false;
        }
        visited[r][c] = true;
        bool ret = findProcess(word, i + 1, visited, board, r + 1, c) ||
                    findProcess(word, i + 1, visited, board, r, c + 1) ||
                    findProcess(word, i + 1, visited, board, r - 1, c) ||
                    findProcess(word, i + 1, visited, board, r, c - 1);
        visited[r][c] = false;
        return ret;
    }
};

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
回溯算法
3
实现 Trie (前缀树)
有效的字母异位词

C++



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xaorig/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
