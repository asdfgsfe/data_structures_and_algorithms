#include <iostream>

using namespace std;

template<typename T, const int kSize>
class ArrayStack
{
public:
    ArrayStack() 
        : index_(0), 
          state_(false)
    {
    }

    void Push(T val)
    {
        if (index_ < kSize)
        {
            arr_[index_++] = val;
            state_ = true;
        }

        return;
    }

    void Pop(void )
    {
        if (index_ > 0)
        {
            --index_;
            state_ = true;
        } 

        return;
    }

    T Top(void)
    {
        T res;
        if (index_ > 0)
        {
            state_  = true;
            res =  arr_[index_ - 1];
        }

        return res;
    }

    const bool State() const
    {
        return state_;
    }

private:
    int index_;
    T arr_[kSize];
    bool state_;
};

template<typename T, const int kSize>
class ArrayQueue
{
public:
    ArrayQueue() 
        : nowSize_(0),
          first_(0), 
          last_(0), 
          state_(false)
    {

    }

    void Push(T val)
    {
        if (nowSize_ < kSize)
        {
            last_ %= kSize;
            arr_[last_++] = val;
            ++nowSize_;
            state_ = true;
        }

        return;
    }

    void Pop(void)
    {
        if (nowSize_ > 0)
        {
            first_ %= kSize;
            ++first_;
            --nowSize_;
            state_ = true;
        }

        return;
    }

    T Front(void)
    {
        T res;
        if (nowSize_ > 0)
        {
            state_ = true;
            res = arr_[first_];
        }

        return res;
    }
    
    const bool State() const
    {
        return state_;
    }

private:
    int nowSize_;
    int first_;
    int last_;
    int arr_[kSize];
    bool state_;
};


int main(void)
{
    ArrayStack<int, 5> as;
    ArrayQueue<int, 5> aq;

    for(int i = 0; i < 5; ++i)
    {
        as.Push(i);
        aq.Push(i + 10);
    }

    for(int i = 0; i < 5; ++i)
    {
        cout << (as.State() ? as.Top() : -1) << " ";
        as.Pop();
    }
    cout << endl;
    
    for(int i = 0; i < 5; ++i)
    {
        cout << (aq.State() ? aq.Front() : -1) << " ";
        aq.Pop();
    }
    cout << endl;

    return 0;
}














