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