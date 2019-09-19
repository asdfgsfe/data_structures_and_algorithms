class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (min_.empty() || x <= min_.top() )
        {
            min_.push(x);
        }
        data_.push(x);
    }
    
    void pop() {
        assert(!empty());
        if (data_.top() == min_.top())
        {
            min_.pop();
        }
        data_.pop();
    }
    
    int top() {
        assert(!empty());
        return data_.top();
    }
    
    int getMin() {
        assert(!empty());
        return min_.top();
    }
    
    bool empty()
    {
        return data_.empty() && min_.empty();
    }
private:
    stack<int> data_;
    stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
