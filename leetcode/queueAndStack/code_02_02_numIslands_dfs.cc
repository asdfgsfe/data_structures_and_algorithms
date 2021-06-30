岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
相关标签
深度优先搜索
广度优先搜索
并查集
数组
矩阵

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/kbcqv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//这道题目的最佳解法是dfs 应为具有动态规划的性质
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
		{
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					InfectProcess(grid, i, j);
					++cnt;
				}
			}
		}
		return cnt;
	}

	void InfectProcess(vector<vector<char>>& grid, int i, int j)
	{
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
		{
			return;
		}
		grid[i][j] = '2';
		InfectProcess(grid, i + 1, j);
		InfectProcess(grid, i, j + 1);
		InfectProcess(grid, i - 1, j);
		InfectProcess(grid, i, j - 1);
	}
};
