//用队列实现栈

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data_.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        assert(!empty());
		while (data_.size() > 1)
		{
			help_.push(data_.front());
			data_.pop();
		}
		int val = data_.front();
		data_.pop();
		data_.swap(help_);
		return val;
    }
    
    /** Get the top element. */
    int top() {
        assert(!empty());
		while (data_.size() > 1)
		{
			help_.push(data_.front());
			data_.pop();
		}
		int val = data_.front();
		data_.pop();
		help_.push(val);
		help_.swap(data_);
		return val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data_.empty() && help_.empty();
    }
private:
	queue<int> data_;
	queue<int> help_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
