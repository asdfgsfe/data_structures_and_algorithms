//������ ����
//�Գ���
//�Է���

string MinStr(vector<string>& strs)
{
	if (strs.empty())
	{
		return string();
	}
	std::sort(strs.begin(), strs.end(),
			[](const string& lhs, const string& rhs)
			{
				return lhs + rhs < rhs + lhs;
			});
	string minStr;
	for (const string& str : strs)
	{
		minStr += str;
	}
	return minStr;
}