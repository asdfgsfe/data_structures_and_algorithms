被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 

示例 1：


输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：

输入：board = [["X"]]
输出：[["X"]]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
相关标签
深度优先搜索
广度优先搜索
并查集
数组
矩阵

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xwfor1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
		//从边界出发 将边界全部为o的相连接的全部感染为某个字母
		//将行的处理和列的处理 各自压缩为一行代码 
        for (int i = 0; i < board[0].size(); ++i) {
			//第一行
            if (board[0][i] == 'O') {
                Infect(board, 0, i);
            }
			//最后一行
            if (board[board.size() - 1][i] == 'O') {
                Infect(board, board.size() - 1, i);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            //第一列
			if (board[i][0] == 'O') {
                Infect(board, i, 0);
            }
			//最后一列
            if (board[i][board[0].size() - 1] == 'O') {
                Infect(board, i, board[0].size() - 1);
            }
        }
		//填充被包围的 和 还原没有被包围的
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void Infect(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'A';
        Infect(board, r - 1, c);
        Infect(board, r + 1, c);
        Infect(board, r, c - 1);
        Infect(board, r, c + 1);
    }
};
