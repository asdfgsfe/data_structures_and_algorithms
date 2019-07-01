#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

template<typename T>
struct List
{
  List (const string& key, const T& v) 
    : val_(v),
      key_(key),
      next_(nullptr)
  {}
  
  T val_;
  string key_;
  List* next_;
};

template<typename T, typename V, int size>
class HashMap
{
public:
  HashMap() 
    : hashMap_(vector<T>(size, nullptr)) {}
  
  void Insert(const string& key, const V& val)
  {
    int id = Hash(key);
    List<V>* pNode = new List<V>(key, val);
    assert(id < size);
    if (hashMap_[id] != nullptr)
    {
      pNode->next_ = hashMap_[id];
    }
    hashMap_[id] = pNode;
  }
 
  T Find(const string& key)
  {
    int id = Hash(key);
    assert(id < size);
    List<V>* pNode = hashMap_[id];
    while (pNode && pNode->key_ != key)
    {
      pNode = pNode->next_;
    }
    return pNode; 
  }

  void Delete(const string& key)
  {
    T pNode = Find(key);
    if (!pNode || !pNode->next_)
    {
      pNode = nullptr;
      return;
    }
    pNode->val_ = pNode->next_->val_;
    pNode->key_ = pNode->next_->key_;
    pNode->next_ = pNode->next_->next_;
  }

  int Hash(const string& key)
  {
    unsigned int hashCode = 0;
    for (const auto ch : key)
    {
      hashCode = (hashCode << 5) + ch;
    }
    return hashCode % size;
  }
private:
  vector<T> hashMap_;
};

int main(void)
{
  HashMap<List<int>*, int, 10> hMap;
  string str = "gw";
  hMap.Insert(str, 34);
  std::cout << hMap.Find(str)->val_ << std::endl;
  hMap.Delete(str);
  std::cout << hMap.Find(str) << std::endl;

  return 0;
}
