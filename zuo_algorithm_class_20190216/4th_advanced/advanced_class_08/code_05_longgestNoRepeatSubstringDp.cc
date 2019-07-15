//套路的递归操作 以每个位置结尾的情况下最长无重复子串 答案必然在其中
//身下的就是由i-1的结果 推出i的结果
int LoggestLength(const string& str)
{
	if (str.empty())
	{
		return 0;
	}
	int loggest = 1;
	for (int i = 0; i < str.size(); ++i)
	{
		loggest = std::max(longgest, LengthProcess(str, i));
	}
	return loggest;
}

int LengthProcess(const string& str, int i)
{
	if (i == 0)
	{
		return 1;
	}
	int next = LengthProcess(str, i - 1);
	for (int k = i - 1; k >= 0; --k)
	{
		if (str[k] == str[i])
		{
			break;
		}
	}
	return i - std::max(next, k);
}