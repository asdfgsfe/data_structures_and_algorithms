#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

string ManacherString(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  string tmp = "#";
  for (int i = 0; i < str.size(); ++i)
  {
    tmp += str[i];
    tmp += "#";
  }
  std::cout << tmp << std::endl;
  return tmp;
}

string ShortestEnd(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  string mStr = ManacherString(str);
  vector<int> pArr(mStr.size());
  int r = -1;
  int c = -1;
  int maxContainsEnd = -1;
  for (int i = 0; i < mStr.size(); ++i)
  {
    pArr[i] = r > i ? std::min(pArr[2 * c - i], r - i) : 1;
    while (i + pArr[i] < mStr.size() && i - pArr[i] >= 0)
    {
      if (mStr[i + pArr[i]] == mStr[i - pArr[i]])
      {
        ++pArr[i];
      }
      else
      {
        break;
      }
    }
    if (i + pArr[i] > r)
    {
      r = i + pArr[i];
      c = i;
    }
    if (r == mStr.size())
    {
      maxContainsEnd = pArr[i];
      break;
    }
  }
  string res;
  std::cout << maxContainsEnd << std::endl;
  for (int i = mStr.size() - 2 * maxContainsEnd; i > 0; i -= 2)
  {
    res += mStr[i];
  }
  return res;
}

int main(void)
{
  string str = "abcd123321";
  std::cout << ShortestEnd(str) << std::endl;

  return 0;
}
