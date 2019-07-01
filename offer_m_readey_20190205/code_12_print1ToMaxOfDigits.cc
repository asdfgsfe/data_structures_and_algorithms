void Print1ToMaxOfDigits1(int n)
{
  if (n < 1)
  {
    return;
  }
  char* number = new char[n + 1];
  memset(number, 0, n);
  numbers[n] = '\0';
  while (!Increment(number))
  {
    printNumner(number);
  }
  delete number;
}

bool Increment(char* number)
{
  assert(number);
  bool isOverFlow = false;
  int nSum = 0;
  int nTakeOver = 0;
  int nLen = strlen(number);
  for (int i = nLen - 1; i >= 0; --i)
  {
    nSum = number[i] - '0' + nTakeOver;
    if (i == nLen - 1)
    {
      ++nSum;
    }
    if (nSum >= 10)
    {
      if (i == 0)
      {
        isOverFlow = true;
      }
      else
      {
        nSum -= 10;
        nTakeOver = 1;
        number[i] = nSum + '0';
      }
    }
    else
    {
      number[i] = nSum + '0';
      break;
    }
  }
  return isOverFlow;
}

void PrintNumber(char* number)
{
  assert(number);
  bool isBegin0 = true;
  int len = strlen(number);
  for (int i = 0; i < len; ++i)
  {
    if (isBegin0 && number[i] != '0')
    {
      isBegin0 = false;
    }
    if (isBegin0 = false)
    {
      printf("%c", number[i]);
    }
  }
  printf("\n");
}

void Print1ToMaxOfDigits(int n)
{
  if (n < 1)
  {
    return;
  }
  vector<char> number(n + 1);
  number[n] = '\0';
  for (int i = 0; i < 10; ++i)
  {
    number[0] = i + '0';
    PrintProcess(number, 0, n);
  }
}

void PrintProcess(vector<char>& number, int index, int length)
{
  if (index == length - 1)
  {
    PrintNumber(number);
    return;
  }
  for (int i = 0; i < 10; ++i)
  {
    number[index + 1] = i + '0';
    PrintProcess(number, index + 1; length);
  }
}
