#include <iostream>
#include <string>

using std::string;

void MoveProcess(int n, const string& from, const string& mid, const string& to)
{
  if (n == 1)
  {
    std::cout << n << " " << from << " " << to << std::endl;
    return;
  }
  MoveProcess(n - 1, from, to, mid);
  std::cout << n << " " << from << " " << to << std::endl;
  MoveProcess(n - 1, mid, to, from);
}

void Hanoi(int n)
{
  if (n < 0)
  {
    return;
  }
  MoveProcess(n, "from", "mid", "to");
}

int main(void)
{
  Hanoi(4);
  return 0;
}
