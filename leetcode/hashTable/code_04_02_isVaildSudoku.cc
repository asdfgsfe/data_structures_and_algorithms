有效的数独
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
 

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xxpit5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
