#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

//template <typename T>
class MedianHolder
{
public:
  void Insert(int val)
  {
    int size = minHeap_.size() + maxHeap_.size();
    int num = val;
    if ((size & 1) == 0)
    {
      if (!maxHeap_.empty() && num < maxHeap_[0])
      {
        maxHeap_.push_back(num);
        num = maxHeap_[0];

        std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<int>());
        std::pop_heap(maxHeap_.begin(), maxHeap_.end(), std::less<int>());
        maxHeap_.pop_back();
      }

      minHeap_.push_back(num);
      std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<int>());
    }
    else
    {
      if (!minHeap_.empty() && num > minHeap_[0])
      {
        minHeap_.push_back(num);
        num = minHeap_[0];

        std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<int>());
        std::pop_heap(minHeap_.begin(), minHeap_.end(), std::greater<int>());
        minHeap_.pop_back();
      }

      maxHeap_.push_back(num);
      std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<int>());
    }
  }
  
  int Median(void)
  {
    int size = minHeap_.size() + maxHeap_.size();
    int t = 0;
    if (size == 0)
    {
      //throw std::exception("not element.");
    }

    if ((size & 1) == 0)
    {
      t = (minHeap_[0] + maxHeap_[0]) / 2;
    }
    else if ((size & 1) == 1)
    {
      t = minHeap_[0];
    }

    return t;
  }

private:
  std::vector<int> minHeap_;
  std::vector<int> maxHeap_;
};

void PrintVector(const std::vector<int>& v)
{
  std::cout << "[";
  std::vector<int>::const_iterator it = v.begin();
  while (it != v.end())
  {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << "]" << std::endl;
}

void GetRandomVector(std::vector<int>& v, unsigned int maxLen, unsigned int maxValue)
{
  ::srand(maxLen);
  int len = ::rand() % maxLen + 1;
  v.resize(len);
  ::srand(maxValue);
  for (int i = 0; i < v.size(); ++i)
  {
    int val = ::rand() % maxValue;
    v[i] = val;
  }
}

int GetMedianOfVector(std::vector<int> v)
{
  int size = v.size();
  int mid = (size - 1) / 2;
  std::sort(v.begin(), v.end());
  if ((size & 1) == 1)
  {
    return v[mid];
  }
  else
  {
    return (v[mid] + v[mid+1]) / 2;
  }
}

int main(void)
{
  bool err = false;
  int testTimes = 200000;
  int errTimes = 0;
  for (int i = 0; i != testTimes; i++) 
  {
    unsigned int len = 30;
    unsigned int maxValue = 1000;
    std::vector<int> v;
    GetRandomVector(v, len, maxValue);
    MedianHolder medianHold;
    for (int j = 0; j != v.size(); j++) 
    {
      medianHold.Insert(v[j]);
    }

    if (medianHold.Median() != GetMedianOfVector(v)) 
    {
      std::cout << medianHold.Median() << " " << GetMedianOfVector(v) << std::endl;
      err = true;
      ++errTimes;
      PrintVector(v);
      break;
    }
  }
  std::string result;
  if (!err)
  {
    result = " today is a beautiful day^_^";
  }
  else
  {
    result = " Oops..what a fuck!";
  }
  std::cout << "errTimes=" << errTimes << result  << std::endl;

  return 0;
}
