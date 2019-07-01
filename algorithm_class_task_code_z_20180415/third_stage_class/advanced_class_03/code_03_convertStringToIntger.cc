#include <iostream>
#include <string.h>

int g_vaild1 = 0;

int IsVaild(const char* str, int len)
{
  if (str[0] != '-' && (str[0] < '0' || str[0] > '9'))
  {
    return -1;
  }
  if (str[0] == '-' && (len == 1 ) || str[1] == '0')
  {
    return -1;
  }
  if (str[0] == '0' && len > 1)
  {
    return -1;
  }
  for (int i = 1; i < len; ++i)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      return -1;
    }
  }
  return 0;
}

int ConvertStringToIntger1(const char* str)
{
  g_vaild1 = -1;
  if (str == NULL || strcmp(str, "\0") == 0)
  {
    return 0;
  }
  int len = strlen(str);
  if (IsVaild(str, len) != 0)
  {
    return 0;
  }
  
  int minus = str[0] == '-' ? -1 : 1;
  int minQ = (signed int)0x80000000 / 10;
  int minR = (signed int)0x80000000 % 10;
  int res = 0;
  for (int i = minus == -1 ? 1 : 0; i < len; ++i)
  {
    int cur = '0' - str[i];
    if (res < minQ || (res == minQ && cur < minR))
    {
      return 0;
    }
    res = res * 10 + cur;
  }
  if (minus == 1 && res == 0x80000000)
  {
    return 0;
  }
  g_vaild1 = 0;
  return minus == 1 ? -res : res;
}

int g_vaild2 = 0;

long long StringToIntCore(const char* str, bool minus)
{
  long long num = 0;
  while (*str != '\0')
  {
    if (*str >= '0' && *str <= '9')
    {
      int flags = minus ? -1 : 1;
      num = num * 10 + flags*(*str - '0');
      if ((!minus && num > 0x7fffffff) || (minus && num < (signed int)(0x80000000)))
      {
        num = 0;
        break;
      }
      ++str;
    }
    else
    {
      num = 0;
      break;
    }
  }
  
  if (*str == '\0')
  {
    g_vaild2 = 0;
  }
  return num;
}

int ConvertStringToIntger2(const char* str)
{
  g_vaild2 = -1;
  int long long num = 0;
  if (str != NULL && *str != '\0')
  {
    bool minus = false;
    if (*str == '+')
    {
      ++str;
    }
    else if (*str == '-')
    {
      minus = true;
      ++str;
    }
    if (*str != '\0')
    {
      num = StringToIntCore(str, minus);
    }
  }
  return (int)num;
}

int main(void)
{
  const char* test1 = "2147483647"; // max in java
  std::cout << ConvertStringToIntger1(test1) << std::endl;

  const char* test2 = "-2147483648"; // min in java
  std::cout << ConvertStringToIntger1(test2) << std::endl;

  const char* test3 = "2147483648"; // overflow
  std::cout << ConvertStringToIntger1(test3) << std::endl;

  const char* test4 = "-2147483649"; // overflow
  std::cout << ConvertStringToIntger1(test4) << std::endl;

  const char* test5 = "-123";
  std::cout << ConvertStringToIntger1(test5) << std::endl;

  std::cout <<"===================================" << std::endl;

  const char* test6 = "2147483647"; // max in java
  std::cout << ConvertStringToIntger2(test6) << std::endl;

  const char* test7 = "-2147483648"; // min in java
  std::cout << ConvertStringToIntger2(test7) << std::endl;

  const char* test8 = "2147483648"; // overflow
  std::cout << ConvertStringToIntger2(test8) << std::endl;

  const char* test9 = "-2147483649"; // overflow
  std::cout << ConvertStringToIntger2(test9) << std::endl;

  const char* test10 = "-123";
  std::cout << ConvertStringToIntger2(test10) << std::endl;


  return 0;
}
