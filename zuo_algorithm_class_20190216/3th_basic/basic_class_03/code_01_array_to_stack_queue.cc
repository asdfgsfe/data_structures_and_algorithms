template<typename T, int capacity>
class ArrayStack
{
public:
  ArrayStack()
    : size_(0)
  {}
  
  void Push(const T& val)
  {
    assert(!Full);
    data_[size_++] = val;
  }
  
  void Pop()
  {
    assert(!Empty());
    --size_;
  }

  T Top() const
  {
    assert(!Empty());
    return data_[size_ - 1];
  }

  bool Empty() const
  {
    return size_ == 0;
  }

  bool Full() const
  {
    return size_ == data_.size();
  }
private:
  int size_;
  std::array<T, capacity>data_;
};

template<typename T, int capacity>
class ArrayQueue
{
  ArrayQueue()
    : size_(0), first_(0), last_(0)
  {}

  bool Empty() const
  {
    return size_ == 0;
  }

  bool Full() const
  {
    return size_ == data_.size();
  }

  void Push(const T& val)
  {
    assert(!Full());
    data[last_] = val;
    last_ = last_ == data_.size() ? 0 : last_ + 1;
  }

  void Pop()
  {
    assert(!Empty());
    --size_;
    first_ = first_ == data_.size() ? 0 : first_ + 1;
  }

  T Top() const
  {
    assert(!Empty());
    return data_[first_];
  }
private:
  int size_;
  int first_;
  int last_;
  std::array<T, capacity>data_;
};
