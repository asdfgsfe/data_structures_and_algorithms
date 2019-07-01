#include <iostream>
#include <string>

using std::string;

void PrintProcess(const string& str, int i, const string& res);
void PrintProcess2(string& str, int i);


//对于每个位置 去尝试分要该位置的字符与不要该位置的字符
//适用于源字符串不可以改变
void PrintAllSubsquences(const string& str)
{
  if (str.empty())
  {
    return;
  }
  string tmp;
  PrintProcess(str, 0, tmp);
}

void PrintProcess(const string& str, int i, const string& res)
{
  if (i == str.size())
  {
    std::cout << res << std::endl;
    return;
  }
  //不要i位置字符
  PrintProcess(str, i + 1, res);
  //要i位置字符
  PrintProcess(str, i + 1, res + str[i]);
}

void PrintAllSubsquences2(string& str)
{
  if (str.empty())
  {
    return;
  }
  PrintProcess2(str, 0);
}

void PrintProcess2(string& str, int i)
{
  if (i == str.size())
  {
    std::cout << str << std::endl;
    return;
  }
  //要i位置字符
  PrintProcess2(str, i + 1);
  char tmp = str[i];
  str[i] = 0;
  //不要i位置字符
  PrintProcess2(str,  i + 1);
  //将i位置字符还原，不影响后面其他位置
  str[i] = tmp;
}

int main(void)
{
  string str = "abc";
  PrintAllSubsquences(str);
  std::cout << std::endl;
  PrintAllSubsquences2(str);

  return 0;
}
