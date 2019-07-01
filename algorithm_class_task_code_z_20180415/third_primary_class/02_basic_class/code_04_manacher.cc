#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

string Manacherstring(const string& str)
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

int MaxLcpsLength(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  string mStr = Manacherstring(str);
  vector<int> pArr(mStr.size());
  int c = -1;
  int r = -1;
  int max = 0x80000000;
  for (int i = 0; i < mStr.size(); ++i)
  {
    pArr[i] = r > i ? std::min(pArr[2 * c - i], r - i) : 1;
    while (i + pArr[i] < mStr.size() && i - pArr[i] >= 0)
    {
      if (mStr[i + pArr[i]] == mStr[i - pArr[i]])
      {
        pArr[i]++;
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
    max = std::max(max, pArr[i]);
  }
  return max - 1;
}

int main(void)
{
  string str = "abc1234321ab";
  std::cout << MaxLcpsLength(str) << std::endl;

  return 0;
}
