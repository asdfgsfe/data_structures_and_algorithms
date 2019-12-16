//�������� ѡ��������x��ʼ���� ��x�㶪�� �����벻���������
//��x�㶪�¼�λf(x, k) ����� ��Ӧ���ж�f(x - 1, k - 1) ����Ӧ���ж�f(n - x, k) n-xλʣ��Ĳ�
//��1~n������ѡȡx����
//��f(n k) = min(f(n, k), max(f(n - x, k), f(x - 1, k - 1)))
//ʵ����x���Զ��ֵ�ȥ����ѡ�� ��Ϊx�ķ�ΧΪ(1~n)�̶� ���ҿ���ͨ��f(n - x, k)��f(x - 1, k - 1)ȷ��x������
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
		 //n==0ʱ ��ʼ����Ϊ0 ����Ҫ ��Ϊdp[i - 1][x - 1], dp[i][j - x]����ȡ����0��
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