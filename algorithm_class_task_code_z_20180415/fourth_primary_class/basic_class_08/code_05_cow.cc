#include <iostream>

int cowNumbers(int n)
{
  if (n < 5)
  {
    return n;
  }
  
  int f1 = 1;
  int f2 = 2;
  int f3 = 3;
  for (int i = 4; i <= n; ++i)
  {
    int tmp1 = f3;
    int tmp2 = f2;
    f3 = f3 + f1;
    f2 = tmp1;
    f1 = tmp2;
  }
  return f3;
}

int cowNumbers2(int n)
{
  if (n < 4)
  {
    return n;
  }
  return cowNumbers2(n-1) + cowNumbers2(n-3);
}

int main(void)
{
  int n = 20;
  std::cout << cowNumbers(n) << std::endl;
  std::cout << cowNumbers2(n) << std::endl;

  return 0;
}
