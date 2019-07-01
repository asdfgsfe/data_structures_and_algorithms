#include <iostream>
#include <vector>
#include <exception>

using std::vector;

template<typename T, const int size>
class ArrayStack
{
public:
  ArrayStack()
    : data_(vector<T>(size)), index_(0)
  {}

  bool empty()
  {
    return index_ == 0;
  }

  void push(const T& val)
  {
    if (index_ == data_.size())
    {
      //std::throw("stack full");
    }
    data_[index_++] = val;
  }

  void pop()
  {
    if (empty())
    {
      //std::throw("stack empty");
    }
    --index_;
  }

  T top()
  {
    if (empty())
    {
      //std::throw("stack empty");
    }
    return data_[index_ - 1];
  }

private:
  vector<T> data_;
  int index_;
};

template<typename T, const int size>
class ArrayQueue
{
public:
  ArrayQueue()
    : data_(vector<T>(size)), first_(0), last_(0), size_(0)
  {}

  bool empty()
  {
    return size_ == 0;
  }

  void push(const T& val)
  {
    if (size_ == data_.size())
    {
      //std::throw("queu full!");
    }
    ++size_;
    data_[last_] = val;
    last_ = last_ == data_.size() - 1 ? 0 : last_ + 1;
  }
 
  void pop()
  {
    if (empty())
    {
      //std::throw("queue empty!");
    }
    --size_;
    first_ = first_ == data_.size() - 1 ? 0 : first_ + 1;
  }

  const T& top()
  {
    if (empty())
    {
      //std::throw("queue empty");
    }
    return data_[first_];
  }

private:
  vector<T> data_;
  int first_;
  int last_;
  int size_;
};

int main(void)
{
  ArrayQueue<int, 3> que;
  ArrayStack<double, 3> st;

  return 0;
}
