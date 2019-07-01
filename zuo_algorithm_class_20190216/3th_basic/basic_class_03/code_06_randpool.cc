template<typename T>
class RandPool
{
  RandPool()
    : size_(0)
  {}

  void Add(const T& key)
  {
    if (keyIndex_.find(key) == keyIndex_.end())
    {
      keyIndex_[key] = size_;
      indexKey[size_++] = key;
    }
  }

  //保存lastkey的值
  //keyIndex: lastKey ->deleteId
  //indexKey: deteteId->lastKey
  //delete key
  //delete lastId
  void Delete(const T& key)
  {
    if (keyIndex_.find(key) != keyIndex_.end())
    {
      int lastId = --size;
      int deleteId = keyIndex[key];
      T lastKey = indexKey[lastId];
      keyIndex[lastKey] = deleteId;
      indexKey[deleteId] = lastKey;
      keyIndex.erase(key);
      indexKey.erase(lastId);
    }
  }

  T key GetRandom()
  {
	assert(!Empty());
	int index = Random(0, size_ - 1);
	auto key = indexKey_.find(index);
	assert(key != indexkey.end()); //fix assert
	return key->second;
  }

private:
  unordered_map<T, int> keyIndex_;
  unordered_map<int, T> indexKey_;
  int size_;
};
