完全平方数
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

 

示例 1：

输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
示例 2：

输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：

1 <= n <= 104
相关标签
广度优先搜索
数学
动态规划

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/kfgtt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	int numSquares(int n) {
		if (n < 3)
		{
			return n;
		}
		int cnt = 0;
		queue<int> nums;
		nums.emplace(n);
		unordered_set<int> visited;
		visited.emplace(n);
		while (!nums.empty())
		{
			int size = nums.size();
			while (size--)
			{
				int num = nums.front();
				nums.pop();
				if (num == 0)
				{
					return cnt;
				}
				for (int i = sqrt(num); i >= 1; --i)
				{
					int next = num - i * i;
					if (next >= 0 && !visited.count(next))
					{
						nums.emplace(next);
						visited.emplace(next);
					}
				}
			}
			++cnt;
		}
		return -1;
	}
};
