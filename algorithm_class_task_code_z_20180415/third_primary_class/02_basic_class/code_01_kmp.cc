#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<int> GetNextArray(const string& str)
{
  if (str.empty())
  {
    return vector<int>();
  }
  if (str.size() == 1)
  {
    return vector<int>(1, -1);
  }
  vector<int> next(str.size());
  next[0] = -1;
  next[1] = 0;
  int i = 2;
  int cn = 0;
  while (i < next.size())
  {
    if (str[i-1] == str[cn])
    {
      next[i++] = ++cn;
    }
    else if (cn > 0)
    {
      cn = next[cn];
    }
    else
    {
      next[i++] = 0;
    }
  }
  return next;
}

int GetIndexOf(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return -1;
  }
  vector<int> next = GetNextArray(s2);
  int i = 0;
  int j = 0;
  while (i < s1.size() && j < s2.size())
  {
    if (s1[i] == s2[j])
    {
      ++i;
      ++j;
    }
    else if (next[j] == -1)
    {
      ++i;
    }
    else
    {
      j = next[j];
    }
  }
  return j == s2.size() ? i - j : -1;
}

int main(void)
{
  string s1 = "abcabcababaccc";
  string s2 = "ababa";
  std::cout << GetIndexOf(s1, s2) << std::endl;

  return 0;
}
