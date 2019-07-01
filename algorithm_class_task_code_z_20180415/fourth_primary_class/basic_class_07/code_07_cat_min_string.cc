#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

string LowestString(vector<string>& strs)
{
  if (strs.empty())
  {
    return string();
  }
  sort(strs.begin(), strs.end(), [&](const string& s1, const string& s2) -> bool {return (s1 + s2) <= (s2 + s1);});
  string res;
  for (const auto& str : strs)
  {
    res += str;
  }
  return res;
}

int main(void)
{
  vector<string> strs1 = { "jibw", "ji", "jp", "bw", "jibw" };
  std::cout << LowestString(strs1) << std::endl;

  vector<string> strs2 = { "ba", "b" };
  std::cout << LowestString(strs2) << std::endl;

  return 0;
}
