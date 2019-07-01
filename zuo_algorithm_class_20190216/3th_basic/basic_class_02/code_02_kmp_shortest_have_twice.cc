#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int EndNextLength(const string& str)
{
  vector<int> next(str.size() + 1);
  next[0] = -1;
  next[1] = 0;
  int pos = 2;
  int cn = 0;
  while (pos < next.size())
  {
    if (str[pos - 1] == str[cn])
    {
      next[pos++]= ++cn;
    }
    else if (cn > 0)
    {
      cn = next[cn];
    }
    else
    {
      next[pos++] = 0;
    }
  }
  return next[next.size() - 1];
}

string Answer(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  if (str.size() == 1)
  {
    return str + str;
  }
  if (str.size() == 2)
  {
    return str[0] == str[1] ? str + str.substr(1) : str + str;
  }
  int endNextLength = EndNextLength(str);
  std::cout << endNextLength << std::endl;
  return str + str.substr(str.size() - endNextLength);//从零开始截取str.size() - endNextLength这个长
}

int main(void)
{
  string t1 = "a";
  std::cout << Answer(t1) << std::endl;
  
  t1 = "aa";
  std::cout << Answer(t1) << std::endl;

  t1 = "ab";
  std::cout << Answer(t1) << std::endl;
  
  t1 = "abcdabcd";
  std::cout << Answer(t1) << std::endl;
  
  t1 = "abracadabra";
  std::cout << Answer(t1) << std::endl;
  return 0;
}
