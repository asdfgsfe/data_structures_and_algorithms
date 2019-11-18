class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, -1);
        dp[0] = 0;
        
        for (int i = 0;i < nums.size();i++) {
            vector<int> temp = dp;
            for (int j = 0;j < 3;j++) {
                if (dp[j] == -1) {
                    continue;
                }
                int next = (j + nums[i]) % 3;
                temp[next] = max(dp[next], dp[j] + nums[i]);
            }
            dp = temp;
        }
        return dp[0];
    }
};

//全部数累加，如果余数是1，那么找最小的一个余数1的数，和两个余数2的数，
//看看哪个小减去哪个，余数为2也是一样。然而我是用递推过