template <typename T>
class MinStack
{
public:
	void Push(const T* v)
	{
		if (min_.empty() || v <= min_.top())
		{
			min_.push(v);
		}
		data_.push(v);
	}

	void Pop()
	{
		assert(!Empty());
		if (data_.top() == min_.top())
		{
			min_.pop();
		}
		data_.pop();
	}

	void Top() const
	{
		assert(!Empty());
		return data_.top();
	}
	T Min() const
	{
		assert(!Empty());
		return min_.top();
	}

	bool Empty() const
	{
		return data_.empty() && min_.empty();
	}
private:
	stack<T> data_;
	stack<T> min_;
};