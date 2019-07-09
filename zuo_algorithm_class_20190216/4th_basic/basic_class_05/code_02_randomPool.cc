template <typename KEY>
class RandomPool
{
	Random()
		: size_(0) 
	{}

	void Insert(const KEY& key)
	{
		data_[key] = size_;
		help_[size_++] = key;
	}
	
	KEY GetRandom() const
	{
		assert(!Empty());
		int id = rand() % size_;
		return help_[id];
	}

	void Delete(const KEY& key)
	{
		assert(!Empty());
		auto lastKey = help.find(size_ - 1);
		assert(lastKey != help.end());
		auto deleteId = data_.find(key);
		assert(deleteId != data_.end());
		data_[lastKey] = *deleteId;
		help_[deleteId] = *lastKey; 
		data_.erase(key);
		help_.erase(size_ - 1);
		--size_;
	}

	bool Empty() const
	{
		assert(data_.size() == help_.size());
		assert(data_.size() == size_);
		return size_ == 0;
	}

private:
	int size_;
	unordered_map<KEY, int> data_;
	unordered_map<int, KEY> help_;
};