#include <iostream>
#include <stack>

template<typename T>
class MinStack
{
public:
    void Push(T val)
    {
        if (!min_.empty() && val <= min_.top())
        {
            min_.push(val);
        }

        s_.push(val);
    }

    void Pop()
    {
        if (!s_.empty() && !min_.empty() && s_.top() == min_.top())
        {
            min_.pop();
        }
        
        s_.pop();
    }

    T GetMin() const
    {
        T res;
        if (!min_.empty())
        {
            res = min_.top();
        }

        return res;
    }

    T Top()
    {
        T res;
        if (!s_.empty())
        {
            res = s_.top();
        }

        return res;
    }

private:
    std::stack<T> s_;
    std::stack<T> min_;
};


int main(void)
{
    MinStack<int> ms;
    ms.Push(1);
    ms.Push(3);
    ms.Push(2);
    ms.Push(5);
    ms.Push(4);
    ms.Push(6);
    ms.Push(3);

    for(int i = 0; i < 7; ++i)
    {
        std::cout << ms.GetMin() << " " << ms.Top() << " ";
        ms.Pop();
    }

    return 0;
}
