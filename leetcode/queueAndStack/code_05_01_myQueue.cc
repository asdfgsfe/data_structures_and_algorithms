class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        assert(!empty());
		if (pop_.empty())
		{
			while (!push_.empty())
			{
				pop_.push(push_.top());
				push_.pop();
			}
		}
		int val = pop_.top();
		pop_.pop();
		return val;
    }
    
    /** Get the front element. */
    int peek() {
        assert(!empty());
		if (pop_.empty())
		{
			while (!push_.empty())
			{
				pop_.push(push_.top());
				push_.pop();
			}
		}
		return pop_.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return push_.empty() && pop_.empty();
    }
private:
	stack<int> push_;
	stack<int> pop_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */