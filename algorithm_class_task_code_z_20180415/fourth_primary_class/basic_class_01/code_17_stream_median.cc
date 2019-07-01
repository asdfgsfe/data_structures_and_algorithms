#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

template<typename T>
class StreamMedian
{
public:
  void Insert(const T& num)
  {
    int size = maxHeap_.size() + minHeap_.size();
    if ((size & 1) == 0)
    {
      if (maxHeap_.size() > 0 && maxHeap_[0] > num)
      {
        maxHeap_.emplace_back(num);
        std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<T>());
        num = maxHeap_[0];
        std::pop_heap(maxHeap_.begin(), maxHeap_.end(), std::less<T>());
        maxHeap_.pop_back();
      }
      minHeap_.emplace_back(num);
      std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<T>());
    }
    else
    {
      if (minHeap_.size() > 0 && minHeap_[0] < num)
      {
        minHeap_.emplace_back(num);
        std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<T>());
        num = minHeap_[0];
        std::pop_heap(minHeap_.begin(), minHeap_.end(), std::greater<T>());
        minHeap_.pop_back();
      }
      maxHeap_.emplace_back(num);
      std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<T>());
    }
  }

  T Median()
  { 
    T median;
    int size = maxHeap_.size() + minHeap_.size();
    if ((size & 1) == 1 && maxHeap_.size() > 0)
    {
      median  = maxHeap_[0];
    }
    else if (maxHeap_.size() > 0 && minHeap_.size() > 0)
    {
      median = (maxHeap_[0] + minHeap_[0]) / 2;
    }
    return median;
  }

private:
  vector<T> maxHeap_;
  vector<T> minHeap_;
};

int main(void)
{
  StreamMedian<int> sm;

  return 0;
}
