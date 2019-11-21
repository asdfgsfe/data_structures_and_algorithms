//dp不仅仅是设置f(m, n)而且要搞明白f(m, n)的实际含义 才能更加灵活的调整参数(m, n)的左右顺序
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sums(n+1, 0);
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = 0;
        for(int i=1; i<=n; ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
				//而前k个数组要能分成i-1份 k至少需要大于等于i-1 因为如果数字少于i-1个 那怎么也不了i-1组]
                for(int k=i-1; k<j; ++k) {
                    int val = max(dp[i-1][k], sums[j]-sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};

//其中 dp[i][j] 表示将数组中前j个数字分成i组所能得到的最小的各个子数组中最大值，
//初始化为整型最大值，如果无法分为i组，那么还是保持为整型最大值。
//为了能快速的算出子数组之和，还是要建立累计和数组，难点就是在于推导状态转移方程了。
//来分析一下，如果前j个数字要分成i组，那么i的范围是什么，由于只有j个数字，
//如果每个数字都是单独的一组，那么最多有j组；如果将整个数组看为一个整体，那么最少有1组，
//所以i的范围是[1, j]，所以要遍历这中间所有的情况，
//假如中间任意一个位置k，dp[i-1][k] 表示数组中前k个数字分成 i-1 组所能得到的最小的各个子数组中最大值，
//[而前k个数组要能分成i-1份 k至少需要大于等于i-1 因为如果数字少于i-1个 那怎么也不了i-1组]
//而 sums[j]-sums[k] 就是后面的数字之和，取二者之间的较大值