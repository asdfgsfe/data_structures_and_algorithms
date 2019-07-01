#include <time.h>
#include <stdlib.h>

#include <iostream>

int Add(int a, int b)
{
  int sum = 0;
  while (b != 0)
  {
    sum = a ^ b;
    b = (a & b) << 1;
    a = sum;
  }
  return sum;
}

int NegativeNum(int a)
{
  return Add(~a, 1);
}

bool IsNegative(int a)
{
  return a < 0;
}

int Minus(int a, int b)
{
  return Add(a, NegativeNum(b));
}

int Multiple(int a, int b)
{
  int res = 0;
  int flag = IsNegative(b) ? NegativeNum(b) : b;
  while (flag != 0)
  {
    if ((flag & 1) != 0)
    {
      res = Add(res, a);
    }
    a <<= 1;
    flag >>= 1;
  }
  return IsNegative(b) ? NegativeNum(res) : res;
}

int Div(int a, int b)
{
  int x = IsNegative(a) ? NegativeNum(a) : a;
  int y = IsNegative(b) ? NegativeNum(b) : b;
  int res = 0;
  for (int i = 31; i > -1; i = Minus(i , 1))
  {
    if ((x >> i) >= y)
    {
      res |= (1 << i);
      x = Minus(x, y << i);
    }
  }
  return IsNegative(a) ^ IsNegative(b) ? NegativeNum(res) : res;
}

int Divide(int a, int b)
{
  if (b == 0)
  {
    return 0;
  }
  if (a == 0x80000000 && b == 0x80000000)
  {
    return 1;
  }
  else if (b == 0x8000000)
  {
    return 0;
  }
  else if (a == 0x80000000)
  {
    int res = Div(Add(a, 1), b);
    return Add(res, Div(Minus(a, Multiple(res, b)), b));
  }
  else 
  {
    return Div(a, b);
  }
}

int main(void)
{
  ::srand((unsigned)time(NULL));
  int a = (int) (rand() % 100000) - 50000;
  int b = (int) (rand() % 100000) - 50000;
  std::cout << "a = " << a << ", b = " << b << std::endl;;
  std::cout << Add(a, b) << std::endl;
  std::cout << (a + b) << std::endl;;
  std::cout << "=========" << std::endl;
  std::cout << Minus(a, b) << std::endl;
  std::cout << (a - b) << std::endl;
  std::cout << "=========" << std::endl;
  std::cout << Multiple(a, b) << std::endl;
  std::cout << (a * b) << std::endl;
  std::cout << "=========" << std::endl;
  std::cout << Divide(a, b) << std::endl;
  std::cout << (a / b) << std::endl;
  std::cout << "=========" << std::endl;

  a = 0x80000000;
  b = 32;
  std::cout << Divide(a, b) << std::endl;
  std::cout << (a / b) << std::endl;

  return 0;
}
