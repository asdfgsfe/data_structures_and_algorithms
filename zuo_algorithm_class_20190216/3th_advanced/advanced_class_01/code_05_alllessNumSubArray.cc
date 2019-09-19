//�����������ֵģ�� �ö���ģ�ͼ�¼��ǰ���ڵ����ֵ����С��
int AllLessNumSubArray(const vector<int>& numbers, int num)
{
  if (numbers.empty())
  {
    return 0;
  }
  deque<int> minNum;
  deque<int> maxNum;
  int i = 0;
  int j = 0;
  int res = 0;
  while (i < numbers.size())
  {
    while (j < numbers.size())
    {
      while (!minNum.empty() && numbers[minNum.front()] >= numbers[j])
      {
        minNum.pop_back()
      }
      minNum.push_back(j);
      while (!maxNum.empty() && numbers[maxNum.front()] <= numbers[j])
      {
        maxNum.pop_back();
      }
      maxNum.push_back(j);
      //���һ�������鲻��� ���������ķ�Χһ������� ���������Ǹ�������
      //max - min > num ��max���� min���С
      if (numbers[maxNum.front()] - numbers[minNum.front()] > num)
      {
        break;
      }
      ++j
    }
    if (minNum.front() == i) //����break iҪ�����ƶ� i�Ѿ����� ���Ե���
    {
      minNum.pop_front();
    }
    if (maxNum.front() == i)
    {
      maxNum.pop_front();
    }
    //һ���������������� ���ڲ���������һ����� max - min <= num
    //����������Сmaxֻ�ܼ�С���߲��� minֻ��������߲���
    res += j - i;
    ++i
  }
  return res;
}
