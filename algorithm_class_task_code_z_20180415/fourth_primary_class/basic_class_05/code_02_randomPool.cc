#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

template<typename T>
class RandomPool
{
public:
  RandomPool() : size_(0) {}
  
  void Insert(const T& key)
  {
    keyIndex_[key] = size_;
    indexKey_[size_++] = key;
  }

  void Delete(const T& key)
  {
    if (keyIndex_.find(key) != keyIndex_.end())
    {
      int deleteId = keyIndex_[key];
      int lastId = --size_;
      T lastKey = indexKey_[lastId];
      keyIndex_[lastKey] = deleteId;
      indexKey_[deleteId] = lastKey;
      keyIndex_.erase(key);
      indexKey_.erase(lastId);
    }
  }

  T GetRandom() const
  {
    if (size_ == 0)
    {
      T t;
      return t;
    }
    //::srand(time(NULL));
    int id = ::rand() % size_;
    const auto it = indexKey_.find(id);
    assert(it != indexKey_.end());
    return it->second;
  }

private:
  unordered_map<T, int> keyIndex_;
  unordered_map<int, T> indexKey_;
  int size_;
};

int main(void)
{
  RandomPool<string> pool;
  pool.Insert("shen");
  pool.Insert("ji");
  pool.Insert("ez");

  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;

  pool.Delete("ez");
  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;
  std::cout << pool.GetRandom() << std::endl;

  return 0;
}

