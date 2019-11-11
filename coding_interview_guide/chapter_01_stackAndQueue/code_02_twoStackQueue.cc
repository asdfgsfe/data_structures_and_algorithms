template<typename T>
class StackQueue
{
public:
	bool Empty() const
	{
		return push_.empty() && pop_.empty();
	}

	void Push(T val)
	{
		push_.push(std::move(val));
	}

	void Pop()
	{
		assert(!Empty());
		if (pop_.empty())
		{
			while (!push_.empty())
			{
				pop_.push(std::move(push_.top()));
				push_.pop();
			}
		}
		assert(!pop_.empty());
		pop_.pop();
	}

	T Top()
	{
		assert(!Empty());
		if (pop_.empty())
		{
			while (!push_.empty())
			{
				pop_.push(std::move(push_.top()));
				push_.pop();
			}
		}
		assert(!pop_.empty());
		return pop_.top();
	}

private:
	stack<T> push_;
	stack<T> pop_;
};