//将每种情况分开分析 代码容易看懂理解
bool IsSelfCorssing(const vector<int>& s)
{
	if (s.size() < 4)
	{
		return false;
	}
	if (s.size() == 4)
	{
		return s[0] >= s[2] && s[3] >= xs[1];
	}
	if (s.size() == 5)
	{
		return (s[3] < s[1] && x[4] >= x[2]) || (x[3] == x[1] && x[4] + x[0] >= x[2]);
	}
	for (int i = 5; i < s.size(); ++i)
	{
		if (x[i - 1] < x[i - 3] && x[i] >= x[i - 2])
		{
			return true;
		}
		if (x[i - 1] < x[i - 3] 
			&& x[i - 2] >= x[i - 4] 
			&& (x[i - 1] + x[i - 5] >= x[i - 3])
			&& x[i] + x[i - 4] >= x[i - 2])
		{
			return true;
		}
	}
	return false;
}