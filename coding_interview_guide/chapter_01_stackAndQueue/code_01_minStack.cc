template <typename T>
class MinStack
{
public:
	bool Empty() const
	{
		if (data_.empty())
		{
			assert(min_.empty());
			return true;
		}
		return false;
	}

	void Push(T val)
	{
		if (min_.empty() || min_.top() >= val)
		{
			min_.push(val);
		}
		data_.push(val);
	}

	T Top() const
	{
		assert(!Empty());
		return data_.top();
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

	T GetMin() const
	{
		assert(!Empty());
		return min_.top();
	}

private:
	stack<T> data_;
	stack<T> min_;
};