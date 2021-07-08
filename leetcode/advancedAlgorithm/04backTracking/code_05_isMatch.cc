 class Solution {
 public:
	 bool isMatch(string s, string p) {
		 if (p.empty())
		 {
			 return s.empty();
		 }
		 vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		 dp.back().back() = true;
		 if (!s.empty() && !p.empty()) 
			//这个地方一定要判断s.empty()因为-2会导致core 
			//依赖于最后2列 倒数第二列出去了最后一个外置之外 其余全部为false 其实就是解决j+1=p.size()的base case
         {
            dp[dp.size() - 2][dp[0].size() - 2] = (s.back() == p.back() || p.back() == '.');
         }
		 for (int i = dp[0].size() - 3; i >= 0; i -= 2)
		 {
			 if (p[i] == '*' || p[i + 1] != '*')
			 {
				 break;
			 }
             dp[dp.size() - 1][i] = true;
		 }
		 for (int i = dp.size() - 2; i >= 0; --i)
		 {
			 for (int j = dp[0].size() - 3; j >= 0; --j)
			 {
				 if (p[j + 1] != '*')
				 {
					 dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i + 1][j + 1];
				 }
				 else
				 {
					 int si = i;
					 while (si < s.size() && (s[si] == p[j] || p[j] == '.'))
					 {
						 if (dp[si][j + 2])
						 {
							 dp[i][j] = true;
							 break;
						 }
						 ++si;
					 }
					 if (!dp[i][j])
					 {
						 //这里一定是dp[si][j + 2]而不是dp[i][j + 2] 
						 //能走到这里表示s已经匹配完了 仅仅是为了匹配x*x*x*这种模式 所以si用上面匹配的结果
						 dp[i][j] = dp[si][j + 2]; 
					 }
				 }
			 }
		 }
		 return dp[0][0];
	 }
 };
