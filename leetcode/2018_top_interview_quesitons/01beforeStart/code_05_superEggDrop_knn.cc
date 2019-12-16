//暴力尝试 选择从任意层x开始尝试 从x层丢下 有碎与不碎两种情况
//从x层丢下记位f(x, k) 如果碎 则应该判断f(x - 1, k - 1) 不碎应该判断f(n - x, k) n-x位剩余的层
//从1~n暴力的选取x尝试
//则f(n k) = min(f(n, k), max(f(n - x, k), f(x - 1, k - 1)))
//实际上x可以二分的去尝试选择 因为x的范围为(1~n)固定 并且可以通过f(n - x, k)与f(x - 1, k - 1)确定x的走向
 class Solution {
 public:
	 int superEggDrop(int K, int N) {
		 if (K == 1 || N == 0 || N == 1)
		 {
			 return N;
		 }
		 int cnt = N;
		 for (int i = 1; i <= N; ++i)
		 { 
			 cnt = std::min(cnt, std::max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i)) + 1);
		 }
		 return cnt;
	 }
 };

//K*N*N
 class Solution {
 public:
	 int superEggDrop(int K, int N) {
		 if (K == 1 || N == 0 || N == 1)
		 {
			 return N;
		 }
		 vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0x7fffffff));
		 for (int i = 1; i < N + 1; ++i)
		 {
			 dp[1][i] = i;
		 }
		 //n==0时 初始条件为0 很重要 因为dp[i - 1][x - 1], dp[i][j - x]可能取到第0列
		 for (int i = 1; i < dp.size(); ++i)
		 {
			 dp[i][0] = 0;
		 }
		 for (int i = 2; i < dp.size(); ++i)
		 {
			 for (int j = 1; j < dp[0].size(); ++j)
			 {
				 for (int x = 1; x <= j; ++x)
				 {
					 dp[i][j] = std::min(dp[i][j], std::max(dp[i - 1][x - 1], dp[i][j - x]) + 1);
				 }
			 }
		 }
		 return dp[K][N];
	 }
 };