#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

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

int main(void)
{
  string str("123");
  PrintAllSubSquences(str);
  
  vector<string> strs = {"123", "456", "789"};
  PrintAllSubSquences2(strs);

  return 0;
}
