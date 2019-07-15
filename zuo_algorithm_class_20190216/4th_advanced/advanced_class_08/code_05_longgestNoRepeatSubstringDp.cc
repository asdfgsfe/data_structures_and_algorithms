//��·�ĵݹ���� ��ÿ��λ�ý�β�����������ظ��Ӵ� �𰸱�Ȼ������
//���µľ�����i-1�Ľ�� �Ƴ�i�Ľ��
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