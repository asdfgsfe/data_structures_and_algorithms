#include <iostream>
#include <exception>
#include <stack>
#include <queue>
#include <algorithm>

template<typename T>
class Stack
{
public:
    void Push(const T& val)
    {
        que_.push(val);
    }

    void Pop()
    {
        if (que_.empty())
        {
            return;
        }

        while (que_.size() > 1)
        {
            T& val = que_.front();
            que_.pop();
            help_.push(val);
        }


        que_.pop();
        std::swap(que_, help_);
    }

    const T& Top()
    {
        if (que_.empty())
        {
            //TODO throw
        }

         while (que_.size() > 1)
        {
            T& val = que_.front();
            que_.pop();
            help_.push(val);
        }

        T& val = que_.front();
        que_.pop();
        help_.push(val);
        std::swap(que_, help_);

        return val;
    }

private:
    std::queue<T> que_;
    std::queue<T> help_;
};


template<typename T>
class Queue
{
public:
    void Push(const T& val)
    {
        stackPush_.push(val);
    }

    void Pop()
    {
        StackPushToPop();
        if (stackPop_.empty())
        {
            //throw new std::exception("stack is empty!");
        }

        stackPop_.pop();
    }

    const T& Front()
    {
        StackPushToPop();
        if (stackPop_.empty())
        {
            //throw new std::exception("stack is empty!");
        }

        return stackPop_.top();
    }

private:
    void StackPushToPop()
    {
         if (stackPop_.empty())
        {
            while (!stackPush_.empty())
            {
                T& val = stackPush_.top();
                stackPush_.pop();
                stackPop_.push(val);
            }
        }
    }
    
    std::stack<T> stackPush_;
    std::stack<T> stackPop_;
};

int main(void)
{
    Stack<int> s;
    Queue<int> q;

    for (int i = 0; i < 5; ++i)
    {
        s.Push(i);
        q.Push(i + 10);
    }

    for(int i = 0; i < 5; ++i)
    {
        std::cout << s.Top() << " ";
        s.Pop();
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << q.Front() << " ";
        q.Pop();

    }
    std::cout << std::endl;

    return 0;
}


