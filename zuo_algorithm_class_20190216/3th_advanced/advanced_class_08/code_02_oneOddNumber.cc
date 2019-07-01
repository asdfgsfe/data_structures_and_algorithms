//打印这个出现奇数次的数
//还有一种打印奇数次出现的次数
int OneOddNumber(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return -1;
  }
  int res = 0;
  for (int number : numbers)
  {
    res ^= number;
  }
  return res;
}

int OneOddNumberTimes(const vector<int>& numbes)
{
  if (numbers.empty())
  {
    return -1;
  }
  int res = 0;
  for (int number : numbers)
  {
    res ^= number;
  }
  int times = 0;
  for (int number : numbers)
  {
    times = res == number ? times + 1 : times;
  }
  return times;
}
