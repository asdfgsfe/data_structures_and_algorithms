#include <iostream>

long long Fabonacci(unsigned int n)
{
  if (n < 2)
  {
    return n;
  }
  return Fabonacci(n - 1) + Fabonacci(n - 2);
}

long long Fabonacci2(unsigned int n)
{
  if (n < 2)
  {
    return n;
  }
  int f0 = 0;
  int f1 = 1;
  int f2 = 0;
  for (unsigned int i = 2; i <= n; ++i)
  {
    f2 = f1 + f0;
    f0 = f1;
    f1 = f2;
  }
  return f2;
}

int main(void)
{
  std::cout << Fabonacci(10) << std::endl;
  std::cout<< Fabonacci(10) << std::endl;

  return 0;
}
