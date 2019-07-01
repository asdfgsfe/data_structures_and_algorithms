#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

template<typename T>
void PrintVector(const vector<T>& values)
{
  for (const auto& val : values)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

void PrintProcess2(vector<string>& strs, int i)
{
  if (i == strs.size())
  {
    PrintVector(strs);
    return;
  }
  PrintProcess2(strs, i + 1);
  string tmp = strs[i];
  strs[i] = string();
  PrintProcess2(strs, i + 1);
  strs[i] = tmp;
}

void PrintProcess(string& str, int i)
{
  if (i == str.size())
  {
    std::cout << str << std::endl;
    return;
  }
  PrintProcess(str, i + 1); //要i位置字符
  char tmp = str[i];
  str[i] = 0;
  PrintProcess(str, i + 1);
  str[i] = tmp;
}

void PrintAllSubSquences(string& str)
{
  if (str.empty())
  {
    return;
  }
  PrintProcess(str, 0);
}

void PrintAllSubSquences2(vector<string>& strs)
{
  if (strs.empty())
  {
    return;
  }
  PrintProcess2(strs, 0);
}

int main(void)
{
  string str("123");
  PrintAllSubSquences(str);
  
  vector<string> strs = {"123", "456", "789"};
  PrintAllSubSquences2(strs);

  return 0;
}
