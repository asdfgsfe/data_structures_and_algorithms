#include <iostream>
#include <string>

using std::string;

void Process(const string& str, int i, const string& res)
{
  if (i == str.size())
  {
    std::cout << res << std::endl;
    return;
  }
  Process(str, i + 1, res);
  Process(str, i + 1, res + str[i]);
}

void PrintAllSubsquences(const string& str)
{
  if (str.empty())
  {
    return;
  }
  Process(str, 0, string());
}

void Process1(string& str, int i)
{
  if (i == str.size())
  {
    std::cout << str << std::endl;
    return;
  }
  Process1(str, i + 1);
  char ch = str[i];
  str[i] = 0;
  Process1(str, i + 1);
  str[i] = ch;
}

void PrintAllSubsquences1(string& str)
{
  if (str.empty())
  {
    return;
  }
  Process1(str, 0);
}

int main(void)
{
  string str = "abc";
  PrintAllSubsquences(str);
  std::cout << "===========" << std::endl;
  PrintAllSubsquences1(str);

  return 0;
}
