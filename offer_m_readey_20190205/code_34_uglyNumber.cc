int KthUglyNumber(int k)
{
  if (k < 1)
  {
    return 0;
  }
  int index = 0;
  int number = 1;
  for (index < k)
  {
    if (IsUglyNumber(number))
    {
      ++index;
    }
    ++number;
  }
  return number;
}

bool IsUglyNumber(int n)
{
  while (n % 2 == 0)
  {
    n /= 2;
  }
  while (n % 3 == 0)
  {
    n /= 3;
  }
  while (n % 5 == 0)
  {
    n /= 5;
  }
  return n == 1 ? true : false;
}

int KthUglyNumber2(int k)
{
  if (k < 1)
  {
    return 0;
  }
  vector<int> uglyNumbers(k);
  uglyNumbers[0] = 1;
  int nextUglyIndex = 1;
  int multiply2 = 0;
  int multiply3 = 0;
  int multiplyy5 = 0;
  while (nextUglyIndex < k)
  {
    int min = std::min(std::min(uglyNumber[multiply2] * 2, uglyNumber[multiply3] * 3), uglyNumber[multiply5] * 5);
    uglyNumber[nextUglyIndex] = min;
    while (uglyNumber[multiply2] * 2 <= min)
    {
      ++multiply2;
    }
    while (uglyNumber[multiply3] * 3 <= min)
    {
      ++multiply3;
    }
    while (uglyNumber[multiply5] * 5 <= min)
    {
      ++multiply5;
    }
    ++nextUglyIndex;
  }
  return uglyNumber[k - 1];
}
