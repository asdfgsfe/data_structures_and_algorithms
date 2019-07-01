#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

int StringToInt(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  stringstream ss;
  ss << str;
  int val = 0;
  ss >> val;
  return val;
}

bool g_InvaildInput = false;

long long Process(const char* pDigit, bool minus)
{
  long long number = 0;
  int flag = minus ? -1 : 1;
  while (*pDigit != '\0')
  {
    if (*pDigit < '0' || *pDigit > '9')
    {
      number = 0;
      break;
    }
    if ((minus && number < (signed int)0x80000000) || (!minus && number > 0x7fffffff))
    {
      number = 0;
      break;
    }
    number = number * 10 + flag * (*pDigit - '0');
    ++pDigit;
  }
  if (*pDigit == '\0')
  {
    g_InvaildInput = false;
  }
  return number;
}

int StringToInt2(const char* pStr)
{
  g_InvaildInput = true;
  long long number = 0;
  if (pStr && *pStr != '\0')
  {
    bool minus = false;
    if (*pStr == '-')
    {
      minus = true;
      ++pStr;
    }
    else if (*pStr == '+')
    {
      ++pStr;
    }
    if (*pStr != '0')
    {
      number = Process(pStr, minus);
    }
  }
  return (int)number;
}

int main(void)
{
  string str = "1333";
  std::cout << StringToInt(str) << std::endl;
  std::cout << StringToInt2(str.c_str()) << std::endl;

  return 0;
}
