template<typename T, typename SIZE>
class ArrStack
{
public:
	ArrStack()
		:	cur_(0)
	{}
	bool Empty() const
	{
		return cur_ == 0;
	}

	bool Full() const
	{
		return cur_ == SIZE;
	}
	
	void Push(const T& v)
	{
		assrrt(!Full());
		data_[cur_++] = v;
	}

	void Pop()
	{
		asseret(!Empty());
		--cur_;
	}
	void Top() const
	{
		assert(!Empty());
		return data_[cur_ - 1];
	}

private:
	int cur_;
	T data_[SIZE]
};
template<typename T, typename SIZE>
class ArrQueue
{
	ArrQueue()
		: first_(0), last_(0), size_(0)
	{}

	bool Empty() const
	{
		return size_ == 0;
	}
	bool Full() const
	{
		return size_ == SIZE;
	}

	void Push(const T& v)
	{
		assert(!Full());
		data[last_++] = v;
		--size_;
		last_ = last_ == SIZE ? 0 : last_;
	}
	void Front() const
	{
		assert(!Empty());
		return data_[first_];
	}
	void Pop()
	{
		assert(!Empty());
		++first_;
		--size_;
		fisrt_ = first_ == SIZE ? 0 : first_;
	}

private:
	int first_;
	int last_;
	int size_;
	T data_[SIZE];
};