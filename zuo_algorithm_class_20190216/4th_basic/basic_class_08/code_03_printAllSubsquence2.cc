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
  vector<string> strs = {"123", "456", "789"};
  PrintAllSubSquences2(strs);

  return 0;
}