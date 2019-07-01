//F(1)=1，F(2)=1, F(n)=F(n-1)+F(n-2)（n>=3，n∈N*）
//夸台阶问题也是斐波那契数列
int Feibo(int n)
{
	if (n < 3)
	{
		return n;
	}
	return Feibo(n - 1) +Feibo(n - 2);
}

//o(n*n)
int FeiboDp(int n)
{
	if (n < 3)
	{
		return n;
	}
	int f1 = 1;
	int f2 = 2;
	int f3 = 0;
	for (int i = 3; i <= n; ++i)
	{
		f3 = f2 + f1;
		f1 = f2;
		f2 =f3;
	}
	return n;
}

//牛永远不会死
//牛问题 f(n) = f(n - 1) + f(n - 3) 
//f(n-1)表示去年的牛不会死会保留到今年
//f(n-3)表示前三年生的小孩会生与他们自己同等数量的小孩
int Cows(int n)
{
	if (n < 4)
	{
		return n;
	}
	int c1 = 1;
	int c2 = 2;
	int c3 = 3;
	int c4 = 0;
	for (int i = 4; i <= n; ++i)
	{
		c4 = c3 + c1;
		c1 = c2;
		c2 = c3;
		c3 = c4;
	}
	return c4;
}

//牛第10年会死
//f(n) = f(n - 1) + f(n - 3) - f(n - 10)
int Cows(int n)
{
	if (n < 4)
	{
		return n;
	}
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 2;
	dp[3] = 3;
	for (int i = 4; i < 10; ++i)
	{
		if (i < 10)
		{
			dp[i] = dp[i - 1] + dp[i - 3];
		}
		else
		{
			dp[i] = dp[i - 1] + dp[i - 3] - dp[i - 10];
		}
	}
	return dp.back();
}