#include <iostream>

bool IsPalindrome(int n)
{
  if (n < 0)
  {
    return false;
  }

  int help = 1;
  while (n / help >= 10)
  {
    help *= 10;
  }
  while (n != 0)
  {
    if (n / help != n % 10)
    {
      return false;
    }

    n = (n % help) / 10;
    help /= 100;
  }
  return true;
}

int main(void)
{
  int n[] = {123, 121, 12321, 1234321, 14211, 34566543};
  for (int i = 0; i < 6; ++i)
  {
    std::cout << IsPalindrome(n[i]) << std::endl;
  }
}

