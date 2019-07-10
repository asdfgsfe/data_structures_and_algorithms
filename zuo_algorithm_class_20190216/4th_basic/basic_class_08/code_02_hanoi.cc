#include <iostream>
#include <string>

using std::string;

void MoveProcess(int n, const string& from, const string& help, const string& to)
{
  if (n == 0)
  {
    return;
  }
  MoveProcess(n - 1, from, to, help);
  std::cout << n << " " << from << " " << to << std::endl; //等价于将只剩余的一个由from移到to
  MoveProcess(n - 1, help, to, from);
}

void Hanoi(int n)
{
  if (n < 0)
  {
    return;
  }
  MoveProcess(n, "from", "help", "to");
}

int main(void)
{
  Hanoi(3);
  return 0;
}
