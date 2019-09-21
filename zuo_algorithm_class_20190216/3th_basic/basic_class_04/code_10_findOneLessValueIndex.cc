//对于局部排序 排序 二分查找
int LessIndex(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return -1;
  }
  if (numbers.size() == 1 || numbers[0] < numbers[1])
  {
    return 0;
  }
  if (numbers[numbers.size() - 1] < numbers[numbes.size() - 2])
  {
    return numbers.size() - 1;
  }
  int l = 1;
  int r = numbers.size() - 2;
  while (l < r)
  {
    int m = (l + r) / 2;
    //注意这里要用同种比较符号 最大值用小于号 最小值用大于好
    if (numbers[m] > numbers[m - 1])
    {
      r = m - 1;
    }
    else if (numbers[m] > numbers[m + 1])
    {
      l = m + 1;
    }
    else
    {
      return m;
    }
  }
  return l;
}
