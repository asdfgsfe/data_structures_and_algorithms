//���������� Ӧ���Ǵ�ӡ�������һ�ε�����
//1.�������2���� 1�ֳ���1�� һ�ֳ���n�� ��ô��kΪ������ż�� kΪż�� �ȼ���oneOddNum kΪ�����ȼ�TwoOddNum
//2.����ж����� 1��������1�� ���඼��k�� kλż�� �ȼ���OneOddNum ����vector kΪ���� ������ĺ��� ��k�������


int OnceNum(const vector<int>& nums, int k)
{
	if (nums.empty() || k < 1)
	{
		return 0x7fffffff;
	}
	vector<int> eor(32, 0);
	for (int i = 0; i < nums.size(); ++k)
	{
		//��ÿ������ת��Ϊk����
		SetEor(eor, nums[i], k);
	}
	int once = 0;
	for (int i = eor.size() - 1; i >= 0; --i)
	{
		once =  once * k + eor[i];
	}
	return once;
}

//��ÿ��k�������ֵĶ�Ӧλ��λ��� ������k�� ��ȡģk��Ȼλ0
void SetEor(vector<int>& eor, int val, int k)
{
	vector<int> sysKNum = SyskNum(val, k);
	for (int i = 0; i < eor.size(); ++i)
	{
		eor[i] = (eor[i] + sysKNum[i]) % k;
	}
}

//��valת��Ϊk��������
vector<int> SysKNum(int val, int k)
{
	vector<int> num(32, 0);
	int idx = 0;
	while (val)
	{
		num[idx++] = val % k;
		val /= k;
	}
	return num;
}
