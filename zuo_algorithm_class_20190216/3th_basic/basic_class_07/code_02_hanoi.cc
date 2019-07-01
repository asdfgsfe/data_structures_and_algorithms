#include <iostream>
#include <string>

using std::string;

void MoveProcess(int n, const string& left, const string& mid, const string& right)
{
  if (n == 1)
  {
    std::cout << left << "->" << right << std::endl;
    return;
  }
  MoveProcess(n - 1, left, right, mid);
  MoveProcess(1, left, mid, right);
  MoveProcess(n - 1, mid, left, right);
}

void Hanoi(int n)
{
  if (n > 1)
  {
    MoveProcess(n, "left", "mid", "right");
  }
}
int main(void)
{
  Hanoi(3);

  return 0;
}
