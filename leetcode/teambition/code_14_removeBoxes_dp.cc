class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		int n = boxes.size();
		int dp[n][n][n] = { 0 };
		for (int i = 0; i < n; ++i)
		{
			for (int k = 0; k <= i; ++k) //��ط�k<=i ��k<n��һ���� ��Ϊ�ò���k>i�����
			{
				dp[i][i][k] = (1 + k) * (1 + k);
			}
		}
		for (int t = 1; t < n; ++t)
		{
			for (int j = t; j < n; ++j)
			{
				int i = j - t; //k��i����һ�����ֵ i����t~j֮�������
				for (int k = 0; k <= i; ++k)
				{
					dp[i][j][k] = (1 + k) * (1 + k) + dp[i + 1][j][0];
					for (int m = i + 1; m <= j; ++m)
					{
						if (boxes[i] == boxes[m])
                        {
                            dp[i][j][k] = std::max(dp[i][j][k], dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                        }
					}
				}
			}
		}
		return dp[0][n - 1][0];
	}
};
