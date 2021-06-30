最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
 

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

pop、top 和 getMin 操作总是在 非空栈 上调用。
相关标签
栈
设计

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/g5l7d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        data_.push(val);
        if (minData_.empty() || minData_.top() >= val) {
            minData_.push(val);
        }
    }
    
    void pop() {
        if (data_.empty() || minData_.empty()) {
            return;
        }
        if (data_.top() == minData_.top()) {
            minData_.pop();
        }
        data_.pop();
    }
    
    int top() {
        assert(!data_.empty());
        return data_.top();
    }
    
    int getMin() {
        assert(!minData_.empty());
        return minData_.top();
    }

private:
    stack<int> data_;
    stack<int> minData_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
