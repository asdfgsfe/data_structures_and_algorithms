int LenProcess(const string& str, int i)
{
  if (i == 0 || str[i] == '(')
  {
    return 0;
  }
  int maxLen = 0;
  int len = LenProcess(str, i - 1);
  int pre = i - len - 1;
  if (pre >= 0 && str[pre] == '(') //到这个位置 str[i]必然位')' 因为str只有括号
  {
	//因为要加LenProcess(str, pre - 1) pre - 1所以要判断pre大于0
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
  //以每个位置结尾的情况下 最长到达多少 选出一个全局最大的 答案必在其中
  //注意这种以每个位置 结尾的情况下怎么怎么样 利用dp的时候可以省略掉外层的for
  //因为dp已经记录了以每个位置结尾的情况下最长的 再算dp的过程中直接选取最大的+
  //以每个位置结尾的情况下怎么怎么样 设当前位i位置f(i) 然后假设自己能拿到以位置i-1结尾的情况下为f(i-1)
  //则利用i-1位的值去推断i位置的值 这是一种套路 如何去推断就是题目的规则 也是当前递归的核心逻辑
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
