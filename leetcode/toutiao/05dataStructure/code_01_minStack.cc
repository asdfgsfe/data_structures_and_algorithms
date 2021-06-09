面试题 03.02. 栈的最小值
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。


示例：

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.



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
