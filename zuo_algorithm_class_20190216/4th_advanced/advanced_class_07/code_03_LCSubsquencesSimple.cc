string LCSubsquences(const string& s1, const string& s2)
{
	if (s1.empty() || s2.empty())
	{
		return string();
	}
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	string lcs;
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		for (int j = dp.size() - 2; j >= 0; --j)
		{
			dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
			if (s1[i] == s2[j])
			{
				dp[i][j] = std::max(dp[i][j], dp[i + 1][j + 1]);
			}
			//��ȡ����������е���һ�ַ���
			//��һ�ַ�����ͨ������dp����ó�
			//ȷ�����ַ��������� ��һ����ѡ��dp[i][j] ��Ϊ�ж��dp[i][j]
			if (dp[i][j] == dp[i + 1][j + 1])
			{
				lcs += s1[i];
			}
		}
	}
	return lcs.reverse();
}