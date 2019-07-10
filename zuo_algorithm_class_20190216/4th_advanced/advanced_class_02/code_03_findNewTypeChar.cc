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

//�����1�Ż� һ����o(k)
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


//���� �п���С��o(k)
string NewTypeChar2(const string& str, int k)
{
  if (str.empty() || k < 1 || k >= str.size())
  {
    return string();
  }
  //�����ҵ������Լ������Сд��ĸ
  //��һ��Сд��ĸ֮��һ����һ���´��Ŀ�ʼ
  int uNum = 0;
  for (int i = k - 1; i >= 0; --i)
  {
    if (::islower(str[i]))
    {
      break;
    }
    ++uNum;
  }
  //����Լ�ǰ������������д��ĸ ��ô��ǰ�ַ�һ����k-1��ʼ ��Ϊÿ������д��һ��
  if ((uNum & 1) == 1)
  {
    return str.substr(k - 1, 2);
  }
   //����Լ�ǰ����ż������д��ĸ �����ǰ��д ��ôk k+1��new���� ��������Լ�
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
