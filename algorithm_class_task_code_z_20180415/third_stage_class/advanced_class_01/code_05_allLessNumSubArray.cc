#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

bool IsVaild(const vector<int>& arr, int left, int right, int num)
{
  int max = arr[left];
  int min =arr[left];
  for (int i = left; i <= right; ++i)
  {
    max = std::max(arr[i], max);
    min = std::min(arr[i], min);
  }

  return max -min <= num;
}

int GetNumOfSubArray(const vector<int>& arr, int num)
{
  if (arr.empty() || num < 0)
  {
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < arr.size(); ++i)
  {
    for (int j = i; j < arr.size(); ++j)
    {
      if (IsVaild(arr, i, j, num))
      {
        ++ans;
      }
    }
  }
  return ans;
}

int GetNumOdSubArray2(const vector<int>& arr, int num)
{
  if (arr.empty() || num < 0)
  {
    return 0;
  }

  deque<int> maxQue;
  deque<int> minQue;
  int l = 0;
  int r = 0;
  int ans = 0;
  while (l < arr.size())
  {
    while (r < arr.size())
    {
      while (!minQue.empty() && arr[minQue.back()] >= arr[r])
      {
        minQue.pop_back();
      }
      minQue.push_back(r);
      while (!maxQue.empty() && arr[maxQue.back()] <= arr[r])
      {
        maxQue.pop_back();
      }
      maxQue.push_back(r);
      if (arr[maxQue.front()] - arr[minQue.front()] > num)
      {
        break;
      }
      ++r;
    }
    if (!minQue.empty() && minQue.front() == l)
    {
      minQue.pop_front();
    }
    if (!maxQue.empty() && maxQue.front() == l)
    {
      maxQue.pop_front();
    }
    ans += r - l;
    ++l;
  }
  return ans;
}

void PrintVector(const vector<int>& v)
{
  std::cout << "[";
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] <<" ";
  }
  std::cout << "]" << std::endl;
}

vector<int> GetRandomVector(unsigned int maxLen)
{
  ::srand(maxLen);
  int len = ::rand() % maxLen + 1;
  vector<int> v;
  v.resize(len);
  ::srand(100000);
  for (int i = 0; i < v.size(); ++i)
  {
    int val = ::rand() % 100000;
    v[i] = val;
  }
  return v;
}


int main(void)
{
  for (int i = 1; i < 5; ++i)
  {
    vector<int> arr = GetRandomVector(30 * i);
    int num = 5 * i;
    PrintVector(arr);
    std::cout << GetNumOdSubArray2(arr, num) << std::endl;
    std::cout << GetNumOfSubArray(arr, num) << std::endl;
    std::cout << "++++++++++++++++++++++" << std::endl;

  }
  return 0;
}






















