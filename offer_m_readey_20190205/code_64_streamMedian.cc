template<typename T>
class Median
{
public:
  void Insert(const T& num)
  {
    if ((minHeap_.size() + maxHeap_.size()) & 1 == 0)
    {
      if (!maxHeap_.empty() && num < maxHeap_[0])
      {
        maxHeap_.push_back(num);
        std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<T>());
        num = maxHeap_[0];
        std::pop_heap(maxHeap_.begin(), maxHeap_.end(), std::less<T>());
        maxHeap_.pop_back();
      }
      minHeap_.push_back(num);
      std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<T>());
    }
    else
    {
      if (!minHeap_.empty() && num > minHeap_[0])
      {
        minHeap_.push_back(num);
        std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<T>());
        num = minHeap_[0];
        std::pop_heap(minHeap_.begin(), minHeap_.end(), std::greater<T>());
        minHeap_.pop_back();
      }
      maxHeap_.push_back(num);
      std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<T>());
    }
  }

  T Median() const
  {
    int size = minHeap_.size() + maxHeap_.size();
    assert(size > 0);
    T median = 0;
    if (size & 1 == 0)
    {
      median = (minHeap_[0] + maxHeap_[0]) / 2;
    }
    else
    {
      median = minHeap_[0];
    }
    return median;
  }

  bool IsEmpty() const
  {
    return minHeap_.empty() && maxHeap_.empty();
  }
private:
  vector<T> minHeap_;
  vector<T> maxHeap_;
};

template<typename T>
class Median2
{
public:
  void Insert(const T& num)
  {
    if ((min_.size() + max_.size()) & 1 == 0)
    {
      if (!max_.empty() && num < *(max_.begin()))
      {
        max_.insert(num);
        num = *(max_.begin());
        max_.erase(max_.begin());
      }
      min_.insert(num);
    }
    else
    {
      if (!min_.empty() && num > *(min_.begin()))
      {
        min_.insert(num);
        num = *(min_.begin());
        min_.erase(min_.begin());
      }
      max_.insert(num);
    }
  }

  T Median() const
  {
    int size = min_.size() + max_.size();
    assert(size > 0);
    if (size & 1 == 1)
    {
      return *(min.begin());
    }
    return (*(min.begin()) + *(max.begin())) / 2;
  }

private:
  std::set<T, std::greater<T>> min_;
  std::set<T, std::less<T>> max_;
};
