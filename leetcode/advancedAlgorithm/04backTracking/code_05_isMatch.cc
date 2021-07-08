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
			//����ط�һ��Ҫ�ж�s.empty()��Ϊ-2�ᵼ��core 
			//���������2�� �����ڶ��г�ȥ�����һ������֮�� ����ȫ��Ϊfalse ��ʵ���ǽ��j+1=p.size()��base case
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
						 //����һ����dp[si][j + 2]������dp[i][j + 2] 
						 //���ߵ������ʾs�Ѿ�ƥ������ ������Ϊ��ƥ��x*x*x*����ģʽ ����si������ƥ��Ľ��
						 dp[i][j] = dp[si][j + 2]; 
					 }
				 }
			 }
		 }
		 return dp[0][0];
	 }
 };
