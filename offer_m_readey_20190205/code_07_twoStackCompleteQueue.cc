template<typename T>
struct StackQueue
{
  void Push(const T& val)
  {
    sPush.push(val);
  }

  void Pop()
  {
    if (sPop.empty())
    {
      while (!sPush.empty())
      {
        T& tmp = sPush.top();
        sPush.pop();
        sPop.push(tmp);
      }
    }
    assert(!sPop.empty());
    sPop.pop();
  }

  T Top()
  {
    if (sPop.empty())
    {
      while (!sPush.empty())
      {
        T& tmp = sPush.top();
        sPush.pop();
        sPop.push(tmp);
      }
    }
    assert(sPop.empty());
    return sPop.top();
  }

private:
  stack<T> sPush;
  stack<T> sPop;
};
