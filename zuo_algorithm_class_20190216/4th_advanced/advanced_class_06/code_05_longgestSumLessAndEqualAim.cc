//Book p115
int MaxLength(const vector<int>& numbers, int aim)
{
	if (numbers.empty())
	{
		return 0;
	}
	//�������鼼��
	vector<int> sums(numbers.size());  //��¼��ÿ��λ�ÿ�ʼ������� ������С���ۼӺ�
	sums.back() = numbers.back();
	unordered_map<int, int> ends; //ȡ�������С�ۼӺ͵�ʱ�����ұߵ�λ�õ�������
	ends[numbers.size() - 1] = numbers.size() - 1;
	for (int i = numbers.size() - 2; i >= 0; --i)
	{
		if (sums[i + 1] <= 0) //����¸��ۼӺ�Ϊ�� ������ͼ��
		{
			sums[i] = numbers[i] + sums[i + 1];
			ends[i] = ends[i + 1];
		}
		else //����������ͼֻ�����Լ�
		{
			sums[i] = numbers[i];
			ends[i] = i;
		}
	}
	int end = 0;
	int sum = 0;
	int longgest = 0;
	//����ط�Ҳ�ǻ�������ģ�� �����������ۼӵ����һֱ�ۼ���
	for (int l = 0; l < numbers.size(); ++l)
	{
		while (end < sums.size() && sum + sums[end] <= aim)
		{
			sum += sums[end];
			end = ends[i];
		}
		longgest = std::max(longgest, end - l);
		sum -= end > l ? numbers[l] : 0;
		end = std::max(end, l + 1); //endʼ�������ұߵ�λ��
	}
	return longgest;
}
