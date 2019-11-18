class Solution {
public:
    int findRotateSteps(string ring, string key) {
		//dp[i][j]��ʾkey�Ĵ�0��i���ַ�ƥ�䵽ring��j�ַ���Ҫ����С��step��
	    vector<vector<int>> dp(key.size() + 1, vector<int>(ring.size()));
		for (int i = dp.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j < dp[0].size(); j++)
			{
				dp[i][j] = INT_MAX;
				for (int k = 0; k < ring.size(); k++)
				{
					if (key[i] == ring[k])
					{
						//һ�����ĳ��ȹ̶� ����ĳһ���ַ� ���Դ�ֻ��Ҫ����˳ʱ����� 
						//��ʱ���û��ĳ��ȼ�ȥ����
						int step = std::min(abs(j - k), (int)(ring.size() - abs(j - k)));
						//����ring�����п����ж����ͬ�����ַ� ���Դ��㿪ʼ�����ĸ�һ��
						//�����������ѡ����С��
						dp[i][j] = std::min(dp[i][j], dp[i + 1][k] + step + 1);
					}
				}
			}
		}
		return dp[0][0];
    }
};