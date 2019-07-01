#include <assert.h>
#include <iostream>
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

template<typename K, typename V>
struct ListNode
{
  K key;
  V val;
  ListNode* last;
  ListNode* next;
  ListNode<K, V>(K k, V v)
    : key(k), val(v), last(nullptr), next(nullptr)
  {}
};

template<typename K, typename V>
class DoubleList
{
public:
  DoubleList()
    : tail_(nullptr), head_(nullptr), size_(0)
  {}
  
  void AddNode(ListNode<K, V>* pNode)
  {
    if (pNode == nullptr)
    {
      return;
    }
    if (head_ == nullptr)
    {
      head_ = pNode;
      tail_ = pNode;
    }
    else
    {
      tail_->next = pNode;
      pNode->last = tail_;
      tail_ = pNode;
    }
    ++size_;
  }

  void MoveNodeToTail(ListNode<K, V>* pNode)
  {
    if (tail_ == pNode)
    {
      return;
    }
    if (head_ == pNode)
    {
      head_ = head_->next;
      head_->last = nullptr;
    }
    else
    {
      assert(pNode->last);
      pNode->last->next = pNode->next;
      assert(pNode->next);
      pNode->next->last = pNode->last;
    }
    tail_->next = pNode;
    pNode->last = tail_;
    pNode->next = nullptr;
    tail_ = pNode;
  }

  ListNode<K, V>* RemoveHead()
  {
    if (head_ == nullptr)
    {
      return nullptr;
    }
    if (head_ == tail_)
    {
      head_ = nullptr;
      tail_ = nullptr;
    }
    else
    {
      ListNode<K, V>* pNode = head_;
      head_ = pNode->next;
      head_->last = nullptr;
      pNode->next = nullptr;
    }
    --size_;
    return head_;
  }
  
  int Size() const
  {
    return size_;
  }
  
  const ListNode<K, V>* Head() const
  {
    return head_;
  }
  const ListNode<K, V>* Tail() const
  {
    return tail_;
  }

  void DisPlay() const
  {
    ListNode<K, V>* pNode = head_;
    while (pNode != nullptr)
    {
      std::cout << pNode->key << " ";
      pNode = pNode->next;
    }
    std::cout << std::endl;
  }

private:
  ListNode<K, V>* tail_;
  ListNode<K, V>* head_;
  int size_;
};

template<typename K, typename V>
class LRUCache
{
public:
  LRUCache(int size)
    : capacity_(size)
  {}
  
  void Set(K key, V value)
  {
    auto it = keyNodes_.find(key);
    if (it != keyNodes_.end())
    {
      it->second->val = value;
      nodes_.MoveNodeToTail(it->second);
    }
    else
    {
      ListNode<K, V>* pNode = new ListNode<K, V>(key, value);
      nodes_.AddNode(pNode);
      keyNodes_[key] = pNode;
      assert(keyNodes_.size() == nodes_.Size());
      if (keyNodes_.size() > capacity_)
      {
        RemoveMostUnusedCache();
      }
    }
  }

  const ListNode<K, V>* Get(K key)
  {
    const auto it = keyNodes_.find(key);
    if (it != keyNodes_.end())
    {
      nodes_.MoveNodeToTail(it->second);
      return it->second;
    }
    return nullptr;
  }

private:
  void RemoveMostUnusedCache()
  {
    nodes_.DisPlay();
    const ListNode<K, V>* pNode = nodes_.Head();
    keyNodes_.erase(pNode->key);
    nodes_.RemoveHead();
    delete pNode;
  }

private:
  unordered_map<K, ListNode<K, V>*> keyNodes_;
  DoubleList<K, V> nodes_;
  const int capacity_;
};

int main(void)
{
  LRUCache<string, int> testCache(3);
  testCache.Set("A", 1);
  testCache.Set("B", 2);
  testCache.Set("C", 3);
  std::cout << testCache.Get("B")->val << std::endl;
  std::cout <<testCache.Get("A")->val << std::endl;
  testCache.Set("D", 4);
  std::cout << testCache.Get("D")->val << std::endl;
  std::cout << testCache.Get("C")->val << std::endl;
  
  return 0;
}
