int LenProcess(const string& str, int i)
{
  if (i == 0 || str[i] == '(')
  {
    return 0;
  }
  int maxLen = 0;
  int len = LenProcess(str, i - 1);
  int pre = i - len - 1;
  if (pre >= 0 && str[pre] == '(') //�����λ�� str[i]��Ȼλ')' ��Ϊstrֻ������
  {
	//��ΪҪ��LenProcess(str, pre - 1) pre - 1����Ҫ�ж�pre����0
    maxLen =  len + 2 + (pre > 0 ? LenProcess(str, pre - 1) : 0);
  }
  return maxLen;
}

int MaxLength(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  int maxLen = 0x80000000;
  //��ÿ��λ�ý�β������� �������� ѡ��һ��ȫ������ �𰸱�������
  //ע��������ÿ��λ�� ��β���������ô��ô�� ����dp��ʱ�����ʡ�Ե�����for
  //��Ϊdp�Ѿ���¼����ÿ��λ�ý�β���������� ����dp�Ĺ�����ֱ��ѡȡ����+
  //��ÿ��λ�ý�β���������ô��ô�� �赱ǰλiλ��f(i) Ȼ������Լ����õ���λ��i-1��β�������Ϊf(i-1)
  //������i-1λ��ֵȥ�ƶ�iλ�õ�ֵ ����һ����· ���ȥ�ƶϾ�����Ŀ�Ĺ��� Ҳ�ǵ�ǰ�ݹ�ĺ����߼�
  for (int i = str.size() - 1; i >= 0; --i)
  {
    maxLen = std::max(maxLen, LenProcess(str, i));
  }
  return maxLen;
}

int MaxLengthDp(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  vector<int> dp(str.size(), 0);
  int maxLen = 0;
  for (int i = 1; i < str.size(); ++i)
  {
    int pre = i - dp[i - 1] - 1;
    if (str[i] == ')' && pre >= 0)
    {
      dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
      maxLen = std::max(maxLen, dp[i]);
    }
  }
  return maxLen;
}
