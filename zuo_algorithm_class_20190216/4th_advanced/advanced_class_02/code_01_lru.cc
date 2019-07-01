template<typename K, typename V>
struct Node
{
  K key;
  V val;
  Node* pNext;
  Node* pPrev;
  Node(const K& k, const V& v)
    : key(k), val(v), pNext(nullptr), pPrev(nullptr)
  {}
};

template<typename K, typename V>
class DoubleList
{
  friend class LRU;
public:
  DoubleList()
    : pHead_(nullptr), pTail_(nullptr), size_(0)
  {}

  void Add(Node<K, V>* pNode)
  {
    if (pNode == nullptr)
    {
      return;
    }
    if (pHead_ == nulptr)
    {
      pHead_ = pNode;
      pTail_ = pNode;
      ++size_;
      return;
    }
    assert(pTail_);
    pTail_->pNext = pNode;
    pNode->pPrev = pTail_;
    pTail_ = pNode;
    ++size_;
  }

  void MoveNodeToTail(Node<K, V>* pNode)
  {
    if (pTail_ == pNode)
    {
      return;
    }
    if (pHead_ == pNode)
    {
      pHead_ = pHead_->pNext;
      pHead_->pPrev = nullptr;
    }
    else
    {
      assert(pNode->pPrev);
      pNode->pPrev->pNext = pNode->pNext;
      assert(pNode->pNext);
      pNode->pNext->pPrev = pNode->pPrev;
    }
    pTail_->pNext = pNode;
    pNode->pNext = nullptr;
    pNode->pPrev = pTail_;
    pTail_ = pNode;
  }

  Node<K, V>* RemoveHead()
  {
    if (pHead_ == nullptr)
    {
      return;
    }
    if (pHead_ == pTail_)
    {
      pHead_ = nullptr;
      pTail_ = nullptr;
    }
    Node<K, V>* pNode = pHead_;
    pHead_ = pHead_->pNext;
    pHead_->pPrev = nullptr;
    pNode->pNext = nullptr;
    --size_;
    return pNode;
  }

private:
  Node<K, V>* pHead_;
  Node<K, V>* pTail;
  int size_;
};

template<typename K,typename V>
class LRU
{
public:
  LRU(int c)
    : capacity_(c)
  {}
  
  void Set(const K& key, const V& val)
  {
    auto it = keyNodes_.find(key);
    if (it != keyNodes_.end())
    {
      it->second->val = val;
      list_.MoveNodeToTail(it->second);
    }
    else
    {
      Node<K, V>* pNode = new Node(key, val);
      list.Add(pNode);
      keyNodes_[key] = pNode;
      assert(keyNodes_.size() == list_.size_);
      if (keyNodes_.size() > capacity_)
      {
        RemoveMostUnusedCache();
      }
    }
  }

  Node<K, V>* Get(const K& key)
  {
    const auto it = keyNodes_.find(key);
    if (it != keyNodes_.end())
    {
      list_.MoveNodeToTail(it->second);
      return it->second;
    }
    return nullptr;
  }

  void RemoveMostUnusedCache()
  {
    Node<K, V>* pNode = list_.RemoveHead();
    keyNodes_.earse(pNode->key);
    delete pNode;
  }

private:
  unordered_map<K, Node<K, V>*> keyNodes_;
  DoubleList<K, V> list_;
  const int capacity_;
};
