#include <iostream>
#include<stack>
#include <queue>

using std::stack;
using std::queue;

template<typename T>
class StackToQueue
{
public:
  bool empty()
  {
    return data_.empty() && help_.empty();
  }

  void push(const T& val)
  {
    data_.push(val);
  }

  const T& top()
  {
    if (empty())
    {
      //std::throw();
    }
    if (help_.empty())
    {
      while (!data_.empty())
      {
        help_.push(data_.top());
        data_.pop();
      }
    }
    return help_.top();
  }

  void pop()
  {
    if (empty())
    {
      throw("queue empty!");
    }
    if (help_.empty())
    {
      while (!data_.empty())
      {
        help_.push(data_.top());
        data_.pop();
      }
    }
    help_.pop();
  }

private:
  stack<T> data_;
  stack<T> help_;
};

template<typename T>
class QueueToStack
{
public:
  void push(const T& val)
  {
    data_.push(val);
  }

  const T& top()
  {
    if (empty())
    {
      //throw;
    }
    if (help_.empty())
    {
      while (data_.size() != 1)
      {
        help_.push(data_.front());
        data_.pop();
      }
    }
    T tmp = data_.front();
    data_.pop();
    help_.push(tmp);
    data_.swap(help_);
    return tmp;
  }

  void pop()
  {
    if (empty())
    {
      //throw
    }
    if (help_.empty())
    {
      while (data_.size() != 1)
      {
        help_.push(data_.top());
        data_.pop();
      }
    }
    data_.pop();
    data_.swap(help_);
  }

  bool empty()
  {
    return data_.empty() && data_.empty();
  }

private:
  queue<T> data_;
  queue<T> help_;
};

int main(void)
{
  StackToQueue<int> que;
  QueueToStack<int> st;

  return 0;
}
