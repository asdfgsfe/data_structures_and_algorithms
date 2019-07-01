bool IsUgly(int num)
{
  while (num % 2 == 0)
  {
    num /= 2;
  }
  while (num % 3 == 0)
  {
    num /= 3;
  }
  while (num % 5 == 0)
  {
    num /= 5;
  }
  return num == 1;
}

int NthUglyNumber1(int n)
{
  if (n < 1)
  {
    return 0;
  }
  int count = 0;
  int num = 0;
  while (count < n)
  {
    ++num;
    if (IsUgly(num))
    {
      ++count;
    }
  }
  return num;
}

int NthUglyNumber2(int n)
{
  if (n < 1)
  {
    return 0;
  }
  vector<int> uglyNumbers(n);
  uglyNumbers[0] = 1;
  int nextId = 1;
  int m2Id = 0;
  int m3Id = 0;
  int m5Id = 0;
  while (nextId < n)
  {
    uglyNumbers[nextId] = std::min(2 * numbers[m2Id], std::min(3 * numbers[m3Id], 5 * numbers[m5Id]));
    if (2 * numbers[m2Id] == uglyNumbers[nextId])
    {
      ++m2Id;
    }
    if (3 * numbers[m3Id] == uglyNumbers[m3Id])
    {
      ++m3Id;
    }
    if (5 * numbers[m5Id] == uglyNumbers[m5Id])
    {
      ++m5Id;
    }
    ++nextId;
  }
  return uglyNumbers[n - 1];
}
