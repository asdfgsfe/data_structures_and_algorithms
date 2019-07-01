template<typename T>
class MinStack
{
public:
  void Push(const T& val)
  {
    data_.push(val);
    if (!minData_.empty && minData_.top() > val)
    {
      return;
    }
    minData_.push(val);
  }

  void Pop()
  {
    if (data_.empty() || minData_.empty())
    {
      return;
    }
    T& tmpVal = data_.top();
    data_.pop();
    if (tmpVal == minData_.top())
    {
      minData_.pop();
    }
  }

  const T& Min() const
  {
    assert(!minData_.empty());
    return minData_.top();
  }

private:
  stack<T> data_;
  stack<T> minData_;
};
