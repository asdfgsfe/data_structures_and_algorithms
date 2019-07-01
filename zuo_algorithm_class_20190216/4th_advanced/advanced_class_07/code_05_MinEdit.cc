#include <iostream>
#include <string>

using std::string;

int EditProcess(const string& exp, const string& pattern, int ei, int pi, int ic, int dc, int rc)
{
  if (ei == exp.size() && pi == exp.size())
  {
    return 0;
  }
  if (ei == exp.size())
  {
    return dc * (pattern.size() - pi - 1);
  }
  if (pi == pattern.size())
  {
    return ic * (exp.size() - ei - 1);
  }
  int minCost = 0;
  if (exp[ei] == pattern[pi])
  {
    minCost = EditProcess(exp, pattern, ei + 1, pi + 1, ic, dc, rc);
  }
  else
  {
    minCost = EditProcess(exp, pattern, ei + 1, pi + 1, ic, dc, rc) + rc;
  }
  minCost = std::min(minCost, EditProcess(exp, pattern, ei + 1, pi, ic, dc, rc) + ic);
  minCost = std::min(minCost, EditProcess(exp, pattern, ei, pi + 1, ic, dc, rc) + dc);
  return minCost;
}

int MinEditCost(const string& exp, const string& pattern, int ic, int dc, int rc)
{
  if (exp.empty())
  {
    return pattern.size() * dc;
  }
  if (pattern.empty())
  {
    return exp.size() * ic;
  }
  return EditProcess(exp, pattern, 0, 0, ic, dc, rc);
}

int main(void)
{
  string str1 = "ab12cd3";
  string str2 = "abcdf";
  //std::cout << MinEditCost(str1, str2, 5, 3, 2) << std::endl;

  str1 = "abc";
  str2 = "adc";
  std::cout << MinEditCost(str1, str2, 5, 3, 2) << std::endl;
  std::cout << MinEditCost(str1, str2, 5, 3, 100) << std::endl;
  
  str1 = "abc";
  str2 = "abc";
  std::cout << MinEditCost(str1, str2, 5, 3, 2) << std::endl;

  str2 = "ab12cd3";
  str1 = "abcdf";
  std::cout <<MinEditCost(str1, str2, 5, 3, 2)<< std::endl;

  str1 = "abcdf";
  str2 = "ab12cd3";
  std::cout <<MinEditCost(str1, str2, 3, 2, 4)<< std::endl;

  str1 = "";
  str2 = "ab12cd3";
  std::cout <<MinEditCost(str1, str2, 1, 7, 5)<< std::endl;

  str1 = "abcdf";
  str2 = "";
  std::cout << MinEditCost(str1, str2, 2, 9, 8)<< std::endl;

  return 0;
}
