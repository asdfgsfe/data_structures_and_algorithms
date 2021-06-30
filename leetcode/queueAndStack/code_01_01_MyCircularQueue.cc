设计循环队列
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
 

提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/kzlb5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k)
		: capacity_(k), size_(0), first_(0), last_(0), data_(capacity_)
	{

	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
		{
			return false;
		}
		data_[last_++] = value;
		last_ = last_ == capacity_ ? 0 : last_;
		++size_;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
		{
			return false;
		}
		++first_;
		first_ = first_ == capacity_ ? 0 : first_;
		--size_;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty())
		{
			return -1;
		}
		return data_[first_];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty())
		{
			return -1;
		}
		int tail = last_ == 0 ? capacity_ - 1 : last_ - 1;
		return data_[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size_ == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size_ == capacity_;
	}
private:
	const int capacity_;
	//利用size 将first_和last解偶
	int size_;
	int first_;
	int last_;
	vector<int> data_;
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/
