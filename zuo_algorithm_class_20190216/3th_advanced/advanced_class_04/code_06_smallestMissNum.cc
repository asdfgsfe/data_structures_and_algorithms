//o(n)
//����Ǹ����Ͷ��� ������iλ�õ�ֵΪnumbers[i] - 1
//����iλ��ȥ���� Ѱ��0����n��Χ�ڵ� ���С�ڻ���������Χ����
int SmallestMissNum(vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int l = 0;
  int r = numbers.size();
  while (l < r)
  {
    if (numbers[l] == l + 1) //�Ѿ����ʵ���λ�� ����Ҫ���� ����һ��λ��
    {
      ++l;
    }
    //numbers[l] < l || numbers[l] > r ��ʾ�����Χ
    //numbers[numbers[l] - 1] == numbers[l] ��ʾ�����ظ���ֵ lλ�õ�ֵnumbers[l] �� numbers[l] - 1��ֵ��� �ظ�
    //��ǰ��ֵ����Ӧ���䵽��λ�õ�ֵ���
    else if (numbers[l] < l || numbers[l] > r || numbers[numbers[l] - 1] == numbers[l]) //������Χ����
    {
      numbers[l] = numbers[--r];
    }
    else
    {
      std::swap(numners[l], numners[numbers[l] - 1]); //�ڷ�Χ�� �����䵽�����Լ�λ��
    }
  }
  return l + 1;
}
