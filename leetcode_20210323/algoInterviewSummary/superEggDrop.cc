//timeout
class Solution {
 public:
	 int superEggDrop(int K, int N) {
        if (K == 1 || N == 0 || N == 1) {
            return N;
        }
        int cnt = 0x7ffffff;
        for (int i = 1; i <= N; ++i) {
            cnt = std::min(cnt, 1 + std::max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i)));
        }
        return cnt;
     }
 };

//timeout
class Solution {
 public:
	 int superEggDrop(int K, int N) {
         if (K == 1 || N == 0 || N == 1) {
             return N;
         }
         vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0x7fffffff));
         for (int i = 0; i < N + 1; ++i) {
            dp[1][i] = i;
         }
         for (int i = 1; i < K + 1; ++i) {
            dp[i][0] = 0;
         }
         for (int i = 2; i < dp.size(); ++i) {
             for (int j = 1; j < dp[0].size(); ++j) {
                 for (int k = 1; k <= j; ++k) {
                    dp[i][j] = std::min(dp[i][j], 1 + std::max(dp[i - 1][k - 1], dp[i][j - k]));
                 }
             }
         }
         return dp[K][N];
     }
 };
