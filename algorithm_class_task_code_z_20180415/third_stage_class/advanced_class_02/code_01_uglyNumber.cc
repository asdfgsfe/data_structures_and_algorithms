#include <iostream>
#include <vector>

bool IsUglyNumber(int n)
{
  while (n % 2 == 0)
  {
    n /= 2;
  }
  while (n % 3 == 0)
  {
    n /= 3;
  }
  while (n % 5 == 0)
  {
    n /= 5;
  }
  return n == 1;
}

int UglyNumber1(int n)
{
  int count = 0;
  int number = 0;
  while (count < n)
  {
    if (IsUglyNumber(++number))
    {
      ++count;
    }
  }
  return number;
}

int UglyNumber2(int n)
{
  int i2 = 0;
  int i3 = 0;
  int i5 = 0;
  int index = 1;
  std::vector<int> help(1, 1);
  while (help.size() < n)
  {
    int ugly = std::min(help[i2] * 2, std::min(help[i3]*3, help[i5]*5));
    help.push_back(ugly);
    if (ugly == help[i2] * 2)
    {
      ++i2;
    }
    if (ugly == help[i3] * 3)
    {
      ++i3;
    }
    if (ugly == help[i5] * 5)
    {
      ++i5;
    }
  }
  return help.back();
}

int main(void)
{
  int test = 8;
  std::cout << UglyNumber1(test) << std::endl;
  std::cout << UglyNumber2(test) << std::endl;

  return 0;
}

