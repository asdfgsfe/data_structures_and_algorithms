#include <iostream>
#include <string>

using std::string;

string NewTypeChar(const string& str, int k)
{
  if (str.empty() || k < 1 || k >= str.size())
  {
    return string();
  }
  int i = 0;
  while (i < str.size())
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      if (i == k)
      {
        return str.substr(i, 1);
      }
      i = i + 1;
    }
    else
    {
      if (i == k || i + 1 == k)
      {
        return str.substr(i, 2);
      }
      i = i + 2;
    }
  }
  return string();
}

//代码比1优化 一定是o(k)
string NewTypeChar3(const string& str, int k)
{
  if (str.empty() || k < 1 || k >= str.size())
  {
    return string();
  }
  int i = 0;
  int pre = 0;
  while (i <= k)
  {
    pre = i;
    i = (str[i] >= 'a' && str[i] <= 'z') ? i + 1 : i + 2;
  }
  return str.substr(pre, i - pre);
}


//左神 有可能小于o(k)
string NewTypeChar2(const string& str, int k)
{
  if (str.empty() || k < 1 || k >= str.size())
  {
    return string();
  }
  //向左找到距离自己最近的小写字母
  //从一个小写字母之后一定是一个新串的开始
  int uNum = 0;
  for (int i = k - 1; i >= 0; --i)
  {
    if (::islower(str[i]))
    {
      break;
    }
    ++uNum;
  }
  //如果自己前面有奇数个大写字母 那么当前字符一定从k-1开始 因为每两个大写是一对
  if ((uNum & 1) == 1)
  {
    return str.substr(k - 1, 2);
  }
   //如果自己前面有偶数个大写字母 如果当前大写 那么k k+1是new类型 否则仅有自己
  if (::isupper(str[k]))
  {
    return str.substr(k, 2);
  }
  return str.substr(k, 1);
}

int main(void)
{
  string str = "aaABCDEcBCg";
  std::cout << NewTypeChar(str, 7) << std::endl;
  std::cout << NewTypeChar(str, 4) << std::endl;
  std::cout << NewTypeChar(str, 10) << std::endl;
  std::cout << NewTypeChar(str, 2) << std::endl;

  std::cout << std::endl;
  std::cout << NewTypeChar2(str, 7) << std::endl;
  std::cout << NewTypeChar2(str, 4) << std::endl;
  std::cout << NewTypeChar2(str, 10) << std::endl;
  std::cout << NewTypeChar2(str, 2) << std::endl;

  return 0;
}
