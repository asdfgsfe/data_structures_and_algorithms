bool g_vaildInput = false;

long long ConvertProcess(const char* pNumber, bool minus)
{
  long long num = 0;
  int flag = minus ? -1 : 1;
  if (pNumber == nullptr || *pNumber == '|0')
  {
    return num;
  }
  while (*pNumber != '\0')
  {
    if (*pNumber < '0' || *pNumber > '9')
    {
      num = 0;
      break;
    }
    if ((minus && (signed int)num < 0x80000000) || (!minus && (signed int)num > 0x7fffffff))
    {
      num = 0;
      break;
    }
    num = num * 10 + (*pNumber - '0') * flag;
    ++pNumber;
  }
  if (*pNumber == '\0')
  {
    g_vailInput = true;
  }
  return num;
}

int StrToInt1(const char* pStr)
{
  g_vaildInput = false;
  bool minus = false;
  long long num = 0;
  if (pStr && *pStr != '0')
  {
    if (*pStr == '-')
    {
      minus = true;
      ++pStr
    }
    else if (*pStr == '+')
    {
      ++pStr;
    }
    if (*pStr != '\0')
    {
      num = ConvertProcess(pStr, minus);
    }
  }
  return (int)num;
}

int ConvertProcess2(const char* pNumber, bool minus)
{
  int minq = 0x80000000 / 10;   //去掉最后一位 剩下的值
  int minr = 0x80000000 % 10;	//拿到最后一位的值
  int num = 0;
  while (pNumber && *pNumber != '\0')
  {
    if (*pNumber < '0' || *pNumber > '9')
    {
      return 0;
    }
    int cur = '0' - *pNumber;
    if (num < minq || (num == minq && cur < minr))
    {
      return 0;
    }
    num = num * 10 + cur;
  }
  if (!minus && num == 0x80000000)
  {
    return 0;
  }
  if (*pNumber == '\0')
  {
    g_vaildInput = true;
  }
  return num;
}

int StrToInt2(const char* pStr)
{
  g_vaildInput = false;
  bool minus = false;
  int num = 0;
  if (pStr && *pStr != '0')
  {
    if (*pStr == '-')
    {
      minus = true;
      ++pStr
    }
    else if (*pStr == '+')
    {
      ++pStr;
    }
    if (*pStr != '\0')
    {
      num = ConvertProcess2(pStr, minus);
    }
  }
  return num;
}
