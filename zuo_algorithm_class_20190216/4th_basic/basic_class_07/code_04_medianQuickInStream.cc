template<typename T>
class MedianQuick
{
public:
  void Insert(const T& val)
  {
    int size = min_.size() + max_.size();
    if (size & 1 == 0)
    {
      if (!max.empty() && max_.front() > val)
      {
        max_.push_back(val);
        std::push_heap(max_.begin(), max_.end(), std::less<T>());
        val = max_.front();
        std::pop_heap(max_.begin(), max_.end(), std::less<T>());
        max_.pop_back();
      }
      min_.push_back(val);
      std::push_heap(min_.begin(), min_.end(), std::greater<T>());
    }
    else
    {
      if (!min_.empty() && min_.front() < val)
      {
        min_.push_back(val);
        std::push_heap(min_.begin(), min_.end(), std::greater<T>());
        val = min_.front();
        std::pop_heap(min_.begin(), min_.end(), std::less<T>());
        min_.pop_back();
      }
      max_.push_back(val);
      std::push_heap(max_.begin(), max_.end(), std::less<T>());
    }
  }

  T Median() const
  {
    assert(!Empty());
    assert(min_.empty());
    int size = max_.size() + min_.size();
    if (size == 1 || size & 1 == 1)
    {
      return min_.front();
    }
    return (min_.front() + max_.front()) / 2;
  }

private:
  std::vector<T> min_;
  std::vector<T> max_;
};
