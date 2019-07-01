template<typename T>
class MedianQuick
{
public:
  Insert(const T& val)
  {
    int size = min_.size() + max_.size();
    if (size & 1 == 1)
    {
      if (!max_.empty() && val < max_.front())
      {
        max.push_back(val);
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
      if (!min_.empty() && val > min_.front())
      {
        min_.push_back(val);
        std::push_heap(min_.begin(), min_.end(), std::greater<T>());
        val = min_.front();
        min_.pop_heap(min_.begin(), min_.end(), std::greater<T>());
        min_.pop_back();
      }
      max_.push_back(val);
      std::push_heap(max_.begin(), max_.end(), std::less<T>());
    }
  }

  T Median() const
  {
    assert(!Empty());
    int size = min_.size() + max_.size();
    if (size & 1 == 1)
    {
      assert(min_.empty());
      return min_.front();
    }
    return (min_.front() + max_.front()) / 2;
  }
private:
  vector<T> min_;
  vector<T> max_;
};
