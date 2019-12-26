//dp timeout
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
        {
			return true;
        }
		vector<bool> dp(nums.size(), false);
		dp.back() = true;
		for (int i = dp.size() - 2; i >= 0; --i)
		{
			for (int j = nums[i]; j > 0; --j)
			{
				if (!dp[i])
				{
					dp[i] = (i + j) >= dp.size() ? true : dp[i + j];
				}
			}
		}
		return dp[0];
    }
};

//贪心
 class Solution {
 public:
	 bool canJump(vector<int>& nums) {
			 if (nums.size() < 2)
			 {
				 return true;
			 }
			 int next = 0;
			 //遍历每个位置 一次就跳到最大距离 
			 for (int i = 0; i < nums.size(); ++i)
			 {
				 //我每次都会跳到最大距离 而我到i位置时 缺落到了i的后面 表示我没有能力向前跳了
				 if (i > next)
				 {
					 return false;
				 }
				 next = std::max(next, i + nums[i]);
			 }
			 return true;
	 }
 };