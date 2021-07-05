//生命游戏
//本题的经典地方在于 上次对数据的改变不能影响到下次 所以出现了用别的数字代码0->1 1->0的状态

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int liveCnt = 0;
                for (int r = -1; r < 2; ++r) { //注意这里一定是++ 不能是+2 因为[i-1][j]是合法位置
                    for (int c = -1; c < 2; ++c) {
                        if (i + r < 0 || i + r >= board.size() || j + c < 0 || j + c >= board[0].size()) {
                            continue;
                        }
                        if (r == 0 && c == 0) {
                            continue;
                        }
                        if (board[i + r][j + c] == 1 || board[i + r][j + c] == 2) {
                            ++liveCnt;
                        }
                    }
                }
                if (board[i][j] == 0 && liveCnt == 3) {
                    board[i][j] = 3;
                }
                if (board[i][j] == 1 && liveCnt != 2 && liveCnt != 3) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
