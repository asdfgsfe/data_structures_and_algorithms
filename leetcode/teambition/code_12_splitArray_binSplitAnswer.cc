class Solution {
public:
	//���ִ𰸵�˼��
	int splitArray(vector<int>& nums, int m) {
		if (nums.empty() || m < 0)
		{
			return 0;
		}
		long long maxSum = 0;
		long long minSum = 0;
		for (int num : nums)
		{
			maxSum += num;
			//Ҫѡ�������з�������͵����ֵ ����������max
			minSum = std::max(minSum, (long long)num);
		}
		while (minSum <= maxSum)
		{
			long long half = (maxSum + minSum) / 2;
			if (CanSplit(nums, m, half))
			{
				maxSum = half - 1;
			}
			else
			{
				minSum = half + 1;
			}
		}
		return minSum;
	}

	bool CanSplit(const vector<int>& nums, int m, long long maxSum)
	{
		long long sum = 0;
		int cnt = 1;
		for (int num : nums)
		{
			sum += num;
			//���Ѿ��ǵ�ǰ�ֳ��������ֵ ����ۼӵ�i �˿��ۼӺʹ����� ���i��ʼ����һ���µ��и�
			//���������з� �����������m �������зֲ��ܽ������зֳ�m�� ��һ�ִ�����з�
			//����������ַ����з�����С�ڵ���m ��ôһ���������� ��Ϊȫ�������� ����һ�����ֺ�ֵ����С�ĺ�
			if (sum <= maxSum)
			{
				continue;
			}
			++cnt;
			sum = num;
			if (cnt > m)
			{
				return false;
			}
		}
		return true;
	}
};