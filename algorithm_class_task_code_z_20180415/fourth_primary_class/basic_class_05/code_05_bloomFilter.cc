#include <iostream>
#include <functional>
#include <vector>

using std::vector;

template<int size, int k>
class BloomFilter
{
  BloomFilter() : bitMap(vector<int>(size, 0)) {}
  void Insert(const string& key)
  {
    for (const auto& hash : hash_)
    {
      int id = hash(key);
      int intIndex = id / 32;
      int bitIndex = id % 32;
      bitMap_[intIndex] = (bitMap_[intIndex] | (1 << bitIndex));
    }
  }
  
  bool IsFilter(const string& key)
  {
    for (const auto& hash : hash_)
    {
      int id = hash(key);
      int intIndex = id / 32;
      int bitIndex = id % 32;
      if (bitMap[intIndex] & (1 << bitIndex) == 1)
      {
        return true;
      }
    }
    return false;
  }

private:
  int k_;
  vector<std::function<int(const string& key)>> hash_;
  vector<int> bitMap_;
};
