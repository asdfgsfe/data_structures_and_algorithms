//F(1)=1��F(2)=1, F(n)=F(n-1)+F(n-2)��n>=3��n��N*��
//��̨������Ҳ��쳲���������
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

//ţ��Զ������
//ţ���� f(n) = f(n - 1) + f(n - 3) 
//f(n-1)��ʾȥ���ţ�������ᱣ��������
//f(n-3)��ʾǰ��������С�������������Լ�ͬ��������С��
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

//ţ��10�����
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