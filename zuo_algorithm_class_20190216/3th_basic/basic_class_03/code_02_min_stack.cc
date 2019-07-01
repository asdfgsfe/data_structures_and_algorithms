template<typename T>
class MinStack
{
public:
  T Min() const
  {
    assert(!Empty());
    return min_.top();
  }
  
  void Push(const T& val)
  {
    data_.push(val);
    if (min_.empty() || val <= min_.top())
    {
      min_.push(val);
    }
  }

  void Pop()
  {
    assert(!Empty());
    if (data_.top() == min_.top())
    {
      min_.pop();
    }
    data_.pop();
  }

  T Top() const
  {
    assert(!Empty());
    return data_.top();
  }

  bool Empty() const
  {
    return data_.empty() && min_.empty();
  }
private:
  std::stack<T> data_;
  std::stack<T> min_;
};
