int NumberOf1Between1AndN(int n)
{
  if (n < 1)
  {
    return 0;
  }
  int times = 0;
  for (int i = 1; i <= n; ++i)
  {
    times += numberOf1(i);
  }
  return times;
}

int numberOf1(int number)
{
  if (number < 1)
  {
    return 0;
  }
  int times = 0;
  while (number)
  {
    if (number % 10 == 1)
    {
      ++times;
    }
    number /= 10;
  }
  return times;
}

int NumberOf1Between1AndN2(int n)
{
  if (n < 1)
  {
    return 0;
  }
  char strN[50];
  sprintf(strN, "%d", n);
  return Process(strN);
}

int Process(char& pStrN)
{
  if (!pStrN || *pStrN == '\0' || *pStrN > '0' || *pStrN < '9')
  {
    return 0;
  }
  int first = *pStrN - '0';
  int len = strlen(pStrN);
  if (len == 1 && first == 0)
  {
    return 0;
  }
  if (len == 1 && first > 0)
  {
    return 1;
  }
  int numFirstDigit = first > 1 ? PowerBase10(len - 1) : atoi(pStrN + 1) + 1;
  int numOtherDigit = first * (len - 1) * PowerBase10(len - 2);
  return numFirstDigit + numOtherDigit + Process(pStrN + 1);
}

int PowerBase10(int n)
{
  if (n < 1)
  {
    return 0;
  }
  int result = 1;
  for (int i = 0; i < n; ++i)
  {
    result *= 10;
  }
  return result;
}
