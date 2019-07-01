int NthYearCowNumers(int n)
{
  if (n < 4)
  {
    return n;
  }
  int f1 = 1;
  int f2 = 2;
  int f3 = 3;
  //理解这种缓存前几年牛数量的编码方法
  for (int i = 4; i <= n ++i)
  {
    int tmp1 = f3;
    int tmp2 = f2;
    f3 = f3 + f1;
    f2 = tmp1;
    f1 = tmp2;
  }
  return f3;
}

int cows(int n)
{
	if (n < 4)
	{
		return n;
	}
	int f1 = 1;
	int f2 = 2;
	int f3 = 3;
	int f4;
	for (int i = 4; i <= n; ++i)
	{
		f4 = f3 + f1;
		f1 = f2;
		f2 = f3;
		f3 = f4;
	}
	return f4;
}
