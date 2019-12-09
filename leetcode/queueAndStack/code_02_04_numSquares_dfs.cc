//如果能进行dfs 就要想到用动态规划优化
class Solution {
    public int numSquares(int n) {
        if (n < 3)
        {
			return n;
        }
		int cnt = 0x7fffffff;
		for (int i = sqrt(n); i >= 1; --i)
		{
			cnt = std::min(cnt, numSquares(n - i * i) + 1);
		}
		return cnt;
    }
}