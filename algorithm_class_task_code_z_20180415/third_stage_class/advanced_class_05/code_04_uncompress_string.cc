#include <iostream>
#include <string>

using std::string;

struct ReturnData
{
  string str;
  int end;

  ReturnData(const string& s, int id)
    : str(s), end(id)
  {}
};

string TimesString(int times, const string& str)
{
  string res;
  for (int i = 0; i < times; ++i)
  {
    res += str;
  }
  return res;
}

ReturnData Process(const string& str, int id)
{
  string builder;
  int times = 0;
  while (id < str.length() && str[id] != '}')
  {
    if (str[id] == '{')
    {
      ReturnData data = Process(str, id + 1);
      builder += TimesString(times, data.str);
      times = 0;
      id = data.end + 1;
    }
    else
    {
      if (str[id] >= '0' && str[id] <= '9')
      {
        times = times * 10 + str[id] - '0';
      }
      if (str[id] >= 'a' && str[id] <= 'z')
      {
        builder += str[id];
      }
      ++id;
    }
  }
  return ReturnData(builder, id);
}

string Uncompress(const string& compressStr)
{
  if (compressStr.empty())
  {
    return "";
  }

  return Process(compressStr, 0).str;
}

int main(void)
{
  string t1 = "3{a}2{bc}";
  string t2 = "3{a2{c}}";
  string t3 = "2{abc}3{cd}ef";
  string t4 = "2{bc3{a}}bc";
  std::cout << Uncompress(t1) << std::endl;
  std::cout << Uncompress(t2) << std::endl;
  std::cout << Uncompress(t3) << std::endl;
  std::cout << Uncompress(t4) << std::endl;

  return 0;
}
