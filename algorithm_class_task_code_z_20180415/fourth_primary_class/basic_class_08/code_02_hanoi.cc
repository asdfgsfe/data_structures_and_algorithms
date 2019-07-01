#include <iostream>
#include <string>

using std::string;

void Process(int n, const string& from, const string& to, const string& help);

void Hanoi(int n)
{
  if (n > 0)
  {
    Process(n, "from", "to", "help");
  }
}

void Process(int n, const string& from, const string& to, const string& help)
{
  if (n == 1)
  {
    std::cout << n << " " << from << "->" << to << std::endl;
  }
  else
  {
    Process(n-1, from, help, to);
    std::cout << n << " " << from << "->" << to << std::endl;
    Process(n-1, help, to, from);
  }
}

int main(void)
{
  int n = 3;
  Hanoi(3);
  return 0;
}
