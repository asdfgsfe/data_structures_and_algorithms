#include <iostream>
#include <string>

using std::string;

void PermutationProcess(string& str, int i)
{
  if (i == str.size())
  {
    std::cout << str << " " << std::endl;
    return;
  }
  for (int s = i; s < str.size(); ++s)
  {
    std::swap(str[i], str[s]);
    PermutationProcess(str, i + 1);
    std::swap(str[i], str[s]);
  }
}

void Permutaion(string& str)
{
  if (str.empty())
  {
    return;
  }
  PermutationProcess(str, 0);
}

int main(void)
{
  string str("abc");
  Permutaion(str);
  
  return 0;
}
