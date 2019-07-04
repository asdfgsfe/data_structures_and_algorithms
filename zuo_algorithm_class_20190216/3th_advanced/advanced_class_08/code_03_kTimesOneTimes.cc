//这题有歧义 应该是打印这个出现一次的数字
//1.如果仅有2种数 1种出现1次 一种出现n次 那么分k为奇数与偶数 k为偶数 等价于oneOddNum k为奇数等价TwoOddNum
//2.如果有多种数 1个仅出现1次 其余都是k次 k位偶数 等价于OneOddNum 返回vector k为奇数 是问题的核心 用k进制求解


int OnceNum(const vector<int>& nums, int k)
{
	if (nums.empty() || k < 1)
	{
		return 0x7fffffff;
	}
	vector<int> eor(32, 0);
	for (int i = 0; i < nums.size(); ++k)
	{
		//将每个数字转换为k进制
		SetEor(eor, nums[i], k);
	}
	int once = 0;
	for (int i = eor.size() - 1; i >= 0; --i)
	{
		once =  once * k + eor[i];
	}
	return once;
}

//将每个k进制数字的对应位置位相加 出现了k次 在取模k必然位0
void SetEor(vector<int>& eor, int val, int k)
{
	vector<int> sysKNum = SyskNum(val, k);
	for (int i = 0; i < eor.size(); ++i)
	{
		eor[i] = (eor[i] + sysKNum[i]) % k;
	}
}

//将val转换为k进制数字
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
