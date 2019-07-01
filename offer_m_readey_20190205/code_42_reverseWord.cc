#include <iostream>
#include <string>

using std::string;

void Reverse(string& str, int left, int right)
{
  if (str.size() < 2 || left < 0 || right >= str.size() || left > right)
  {
    return;
  }
  while (left < right)
  {
    std::swap(str[left++], str[right--]);
  }
}

void ReverseWord(string& word)
{
  if (word.size() < 2)
  {
    return;
  }
  Reverse(word, 0, word.size() - 1);
  int left = 0;
  int right = 0;
  while (left <= right && right <= word.size())
  {
    if (word[right] == ' ' || right == word.size())
    {
      Reverse(word, left, right - 1);
      left = right + 1;
    }
    ++right;
  }
}

void LeftReverseString(string& str, int k)
{
  if (str.size() < 2 || k < 1 || k >= str.size())
  {
    return;
  }
  Reverse(str, 0, k - 1);
  Reverse(str, k, str.size() - 1);
  Reverse(str, 0, str.size() - 1);
}

int main(void)
{
  string word = "i am a student.";
  ReverseWord(word);
  std::cout << word << std::endl;

  string str = "abcdefg";
  LeftReverseString(str, 2);
  std::cout << str << std::endl;

  return 0;
}
