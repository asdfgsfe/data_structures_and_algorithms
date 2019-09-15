#include <iostream>
#include <vector>

using std::vector;

void PrintVector(const vector<int>& v)
{
  for (int val : v)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
//
//仅仅只是一次partirion是不行的 必须一直partitin直到随机化分出来饿的位置为k 就是想要的答案
//错误的接发2
vector<int> kLeastNumbers(vector<int>& numbers, int k)
{
  if (numbers.empty() || k > numbers.size())
  {
    return vector<int>();
  }
  int left = 0;
  int right = numbers.size() - 1;
  std::swap(numbers[k - 1], numbers[right]);
  while (1)
  {
    while (left < numbers.size() && numbers[left++] < numbers[numbers.size() - 1]){}
    while (right > 0 && numbers[--right] > numbers[numbers.size() - 1]){}
    if (left > right)
    {
      break;
    }
    std::swap(numbers[left], numbers[right]);
  }
  vector<int> result(k);
  for (int i = 0; i < k; ++i)
  {
    result[i] = numbers[i];
  }
  return result;
}

//利用红黑树的排序去解
multiset<int, std::greater<int>()> KLeastNumbers(const vector<int>& numbers, int k)
{
  if (numbers.empty() || k < 0 || k > numbers.size())
  {
    return multiset<int, std::greater<int>>();
  }
  multiset<int, std::greater<int>()> mSet;
  for (int number : numbers)
  {
    if (mSet.size() < k)
    {
      mSet.insert(number);
    }
    else
    {
      const auto it = mSet.begin();
      if (*it > number)
      {
        mSet.erase(it);
        mSet.insert(number);
      }
    }
  }
  return mSet;
}

int main(void)
{
  vector<int> numbers = {4, 5, 1, 6, 2, 7, 3, 8};
  vector<int> result = kLeastNumbers(numbers, 4);
  PrintVector(result);
}
