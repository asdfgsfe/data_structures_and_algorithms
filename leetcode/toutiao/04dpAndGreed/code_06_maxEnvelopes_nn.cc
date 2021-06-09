class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty() || envelopes[0].empty()) {
            return 0;
        }
        //w从小到大排序 h从大到小排序
        //有两个纬度 排序w 保证只有一个可变维度 然后求最长递增子序列
        std::sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] > rhs[1];
            });
        int maxNums = 1;
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                }
            }
            maxNums = std::max(maxNums, dp[i]);
        }
        return maxNums;
    }
};
