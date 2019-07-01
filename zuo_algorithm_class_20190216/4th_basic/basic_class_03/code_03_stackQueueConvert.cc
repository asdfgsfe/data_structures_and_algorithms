template<typename T>
class StackToQue
{
public:
	void Push(const T& v)
	{
		push_.push(v);
	}

	void Pop()
	{
		assert(!Empty());
		if (pop_.empty())
		{
			while (!push.empty())
			{
				pop_.push(push_.top());
				push_.pop();
			}
		}
		assert(!pop_.empty());
		pop_.pop()
	}

	T Top()
	{
		assert(!Empty());
		if (pop_.empty())
		{
			while (!push_.empty())
			{
				pop_.push(push_.top());
				push_.pop();
			}
		}
		assert(pop_.empty());
		return pop_.top();
	}
	
	bool Empty() const
	{
		return push_.empty() && pop_.empty();
	}

private:
	stack<T> push_;
	stack<T> pop_;
};

template<typename T>
class QueToStack
{
	void Push(const T& v)
	{
		data_.push(v)
	}

	void Pop()
	{
		assert(!Empty());
		assert(help_.empty());
		while (data_.size() > 1)
		{
			help_.push(data_.top());
			data_.top();
		}
		data_.pop();
		std::swap(data_, help_);
	}

	T Top()
	{
		assert(!Empty());
		assert(help_.empty());
		while (data_.size() > 1)
		{
			help_.push(data_.top());
			data_.pop();
		}
		T tmp = data_.top();
		help_.push(data_.top());
		data_.pop();
		std::swap(data_, help_);
		return tmp;
	}

private:
	queue<T> data_;
	queue<T> help_;
};