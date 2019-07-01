template<typename T>
class StackToQueue
{
public:
  void Push(const T& val)
  {
    push_.push(val);
  }
  
  void Pop()
  {
    assert(!Empty());
    if (pop_.empty() && !push_.empty())
    {
      while (!push_.empty())
      {
        pop_.push(push_.top());
        push_.pop();
      }
    }
    assert(!pop_.empty());
    pop_.pop();
  }

  void Top() 
  {
    assert(!Empty());
    if (pop_.empty() && !push_.empty())
    {
      while (!push.empty())
      {
        pop_.push(push_.top());
        push_.pop();
      }
    }
    assert!(pop_.empty());
    return pop_.top();
  }
private:
  std::stack<T> push_;
  std::stack<T> pop_;
};

template<typename T>
class QueueToStack
{
public:
  void Push(const T& val)
  {
    que.push(val);
  }

  bool Empty() const
  {
    return que_.empty() && help_.empty();
  }

  void Pop()
  {
    assert(!Empty());
    assert(help_.empty());
    while (que.size() != 1)
    {
      help_.push(que.front());
      que.pop();
    }
    que.pop();
    std::swap(que_, help_);
  }
  
  T Top()
  {
    assert(!Empty());
    assert(help_.empty());
    while (que.size() != 1)
    {
      help_.push(que.front());
      que.pop();
    }
    assert(que.size() == 1);
    T tmp = que.front();
    que.pop();
    help_.push(tmp);
    std::swap(help_, que_);
    return tmp;
  }
private:
  std::queue<T> que_;
  std::queue<T> help_;
};
