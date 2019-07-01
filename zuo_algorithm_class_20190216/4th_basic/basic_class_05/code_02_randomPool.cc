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
		int id = rand() % size_;
		return help_[id];
	}

	void Delete(const KEY& key)
	{
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

private:
	int size_;
	unordered_map<KEY, int> data_;
	unordered_map<int, KEY> help_;
};