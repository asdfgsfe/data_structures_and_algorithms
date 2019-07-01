#include <iostream>

long Factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  long result = 1;
  for (int i = 1; i <= n; ++i)
  {
    result *= i;
  }
  return result;
}

long Factorial2(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  return (long)n * Factorial2(n-1);
}

int main(void)
{
  int n = 5;
  std::cout << Factorial(n) << std::endl;
  std::cout << Factorial2(n) << std::endl;

  return 0;
}
