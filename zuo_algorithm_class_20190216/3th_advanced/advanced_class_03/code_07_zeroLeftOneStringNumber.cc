//无后效问题的递归
//第一个位置必须是1
//尝试 如果第二个位置0字符 从i+2后面有多少种方法
//尝试 如果第二个位置为1 和第一个位置为1字符一样 从i+1后面尝试有多少种方法
//两者加起来就是最终的结果
//动态规划就是数学归纳法 递归的basecase就是数学归纳法的起点 往后推

int CountProcess(int i, int n)
{
  if (i == n - 1)
  {
    return 2;
  }
  if (i == n)
  {
    return 1;
  }
  //CountProcess(i + 1, n)第二个位置填1
  //CountProcess(i + 2, n) 第二个位置填0
  //表示i位置选定 从i后面一个位置去尝试有多少中方法
  return CountProcess(i + 1, n) + CountProcess(i + 2, n);
}

int CountStringNum1(int n)
{
  if (n  < 1)
  {
    return 0;
  }
  return CountProcess(1, n);
}

//本质f(n) = f(n-1) + f(n-2)
//对于1维动态规划考虑直接用数据归纳法递推出数学公式
int CountStringNum2(int n)
{
  if (n < 1)
  {
    return 0;
  }
  vector<int> dp(n);
  dp[n - 1] = 1;
  dp[n - 2] = 2;
  for (int i = n - 3; i >= 0; --i)
  {
    dp[i] = dp[i + 1] + dp[i + 2];
  }
  return dp[0];
}

int CountStringNum3(int n)
{
  if (n < 1)
  {
    return 0;
  }
  int f1 = 1;
  int f2 = 2;
  int f3 = 0;
  for (int i = 3; i <= n; ++i)
  {
    f3 = f2 + f1;
    f1 = f2;
    f2 = f3;
  }
  return f3;
}
