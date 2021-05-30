class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        data_.push(val);
        if (curMin_.empty() || val <= curMin_.top()) {
            curMin_.push(val);
        }
    }
    
    void pop() {
        assert (!data_.empty() && !curMin_.empty());
        int val = data_.top();
        data_.pop();
        if (val == curMin_.top()) {
            curMin_.pop();
        }
    }
    
    int top() {
        assert (!data_.empty());
        return data_.top();
    }
    
    int getMin() {
        assert (!curMin_.empty());
        return curMin_.top();
    }

private:
    stack<int> data_;
    stack<int> curMin_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


