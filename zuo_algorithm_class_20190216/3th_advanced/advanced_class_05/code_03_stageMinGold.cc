//StageMinGold
int KillProcess(const vector<int>& knights, int i, int dragon)
{
  if (dragon < 0)
  {
    return 0x7fffffff;
  }
  if (i == knights.size())
  {
    return dragon == 0 ? 1 : 0x7fffffff;
  }
  int notIncludeCur = KillProcess(knights, i + 1, dragon);
  int includeCur = KillProcess(knights, i + 1, dragon - knights[i]) + knights[i];
  return std::min(notIncludeCur, includeCur);
}

int StageMinGold(const vector<int>& knights, const vector<int>& dragons)
{
  if (knights.empty() || dragons.empty())
  {
    return 0;
  }
  int res = 0;
  for (int dragon : dragons)
  {
    res += KillProcess(knights, 0, dragon);
  }
  return res;
}

//o(n*n)
int StageMinGoldDp(const vector<int>& knights, const vector<int>& dragons)
{
  if (knights.empty() || dragons.empty())
  {
    return 0;
  }
  int res = 0;
  for (int dragon : dragons)
  {
    vector<vector<int>> dp(knights.size() + 1, vector<int>(dragon + 1, 0x7fffffff));
    dp[dp.size() - 1][0] = 0;
    for (int i = dp.size() - 2; i >= 0; --i)
    {
      for (int j = dp[0].size() - 1; j >= 0; --j)
      {
        if (j - knights[i] >= 0)
        {
          dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j - knights[i]] + knights[i]);
        }
      }
    }
    res += dp[0][dragon];
  }
  return res;
}

//o(n*log(n))
int MinGold2(const vector<int>& dragons, const vector<int>& knights)
{
	if (dragons.empty() || knights.empty())
	{
		return 0;
	}

	int len = 0;	
	for (int i = 0; i < knights.size(); ++i)
	{
		len += knights[i];
	}
	vector<int> dp(len+1, 0x7fffffff);//dp���������������е��ۼӺ� ��������Ⱥ�ٳ��������ۼӺ͵ķ�ʽ
	dp[0] = 0;
	dp[knights[0]] = knights[0];
	PrintDp(dp);
	//for�������� ��i��β������� ���������е��ۼӺ�
	//dp[j]��ʾ��i��β������������е� �ۼӺ�Ϊj�� ������ۼӳ���j==dp[j]
	//��ʵ���ǽ���dp���±������������ ��һ�������±��������Ŀ
	//dp[j] = std::min(dp[j], dp[j-knights[i]] + knights[i]) ���Ǳ�ʾ�������ܲ����ۼӳ���Ϊdp[j]��ֵ 
	//��Ϊdp[j]λ�õ�ֵ�̶�������ۼӳ��� ����j ȡ��С��Ϊ�����ֳ��ۼӲ��������
	//Ҳ���Ի���std::max() ֻ����copy��ʱ����Ҫ ��i-dp.size max��ʽ����
	for (int i = 1; i < knights.size(); ++i)
	{
		for (int j = 1; j <= len; ++j)
		{
			if (j - knights[i] >= 0 && dp[j-knights[i]] < 0x7fffffff)
			{
				dp[j] = std::min(dp[j], dp[j-knights[i]] + knights[i]);
				//dp[j] = std::max(dp[j], dp[j-knights[i]] + knights[i]);
			}
		}
		PrintDp(dp);
	}
	//copy 
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		dp[i] = std::min(dp[i], dp[i+1]); //��֤��С��������
	}	
	//��std::max��ʽ��Ӧ
	//for (int i = 1; i < dp.size(); ++i)
	//{
		//dp[i] = std::max(dp[i], dp[i-1]);
	//}
	PrintDp(dp);

	int res = 0;
	for (int i = 0; i < dragons.size(); ++i)
	{
		int cost = MaxLeftMost(dp, dragons[i]);
		if (cost == 0x7fffffff)
		{
			return 0x7fffffff;
	}
	res += cost;
	}
	return res;
}

int main(void)
{
  vector<int> knights2 = {2, 10, 5};
  vector<int> dragons2 = { 3, 8, 6 };
  std::cout << StageMinGold(dragons2, knights2) << std::endl;
  std::cout << StageMinGoldDp(dragons2, knights2) << std::endl;
  
  return 0;
}
