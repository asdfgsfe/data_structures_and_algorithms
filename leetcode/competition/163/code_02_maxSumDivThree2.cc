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

//ȫ�����ۼӣ����������1����ô����С��һ������1����������������2������
//�����ĸ�С��ȥ�ĸ�������Ϊ2Ҳ��һ����Ȼ�������õ��ƹ�