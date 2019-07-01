#include <iostream>
#include <string>

using std::string;

void Permutaions(string& str, int index)
{
  if (index == str.size())
  {
    std::cout << str << std::endl;
    return;
  }
  for (int i = index; i < str.size(); ++i)
  {
    std::swap(str[i], str[index]);
    Permutaions(str, index + 1);
    std::swap(str[i], str[index]);
  }
}

void PrintAllPemutaions(string& str)
{
  if (str.empty())
  {
    return;
  }
  Permutaions(str, 0);
}

int main(void)
{
  string test = "abc";
  PrintAllPemutaions(test);

  return 0;
}
