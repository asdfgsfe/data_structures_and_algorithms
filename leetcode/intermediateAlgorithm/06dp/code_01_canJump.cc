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

//̰��
 class Solution {
 public:
	 bool canJump(vector<int>& nums) {
			 if (nums.size() < 2)
			 {
				 return true;
			 }
			 int next = 0;
			 //����ÿ��λ�� һ�ξ����������� 
			 for (int i = 0; i < nums.size(); ++i)
			 {
				 //��ÿ�ζ������������� ���ҵ�iλ��ʱ ȱ�䵽��i�ĺ��� ��ʾ��û��������ǰ����
				 if (i > next)
				 {
					 return false;
				 }
				 next = std::max(next, i + nums[i]);
			 }
			 return true;
	 }
 };