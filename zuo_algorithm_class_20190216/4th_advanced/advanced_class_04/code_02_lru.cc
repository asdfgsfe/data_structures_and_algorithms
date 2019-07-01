//从尾部添加 尾部的节点是最新的
//从头部弹出 头部节点是最久的
template<typename K, typename V>
struct Node
{
  K key;
  V val;
  Node<K, V>* pPre;
  Node<K, V>* pNext;
  Node<K, V>() {}
  Node<K, V>(const K& k, const V& v)
    : key(k), val(v), pPre(nullptr), pNext(nullptr)
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

  void AddNode(Node<K, V>* pNode)
  {
    if (pNode == nullptr)
    {
      return;
    }
    if (pHead_ == nullptr)
    {
      pHead_ = pNode;
      pTail_ = pNode;
    }
    else
    {
      pTail_->pNext = pNode;
      pNode->pPre = pTail_;
      pTail_ = pNode;
    }
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
      pHead_->pPre = nullptr;
    }
    else
    {
      assert(pNode->pPre);
      pNode->pPre->pNext = pNode->pNext;
      assert(pNode->pNext);
      pNode->pNext->pPre = pNode->pPre;
    }
    pTail_->pNext = pNode;
    pNode->pRre = ptail_;
    pTail_ = pNode;
    pTail_->pNext = nullptr;
  }

  Node<K, V>* RemoveHead()
  {
    if (pHead_ == nullptr)
    {
      return nullptr;
    }
    if (pHead_ == pTail_)
    {
      pHead_ == nullptr;
      pTail_ == nullptr;
      --size_;
      return nullptr;
    }
    Node<K, V>* pNode = pHead_;
    pHead_ = pHead_->pNext;
    pHead_->pPre = nullptr;
    pNode->pNext = nullptr;
    --size_;
    return pNode;
  }

private:
  Node<K, V>* pHead_;
  Node<K, V>* pTail_;
  int size_;
};

template<typename K, typename V>
class LRU
{
public:
  Node<K, V>* Get(const K& key)
  {
    auto it = keyNodes_.find(key);
    if (it == keyNodes_.end())
    {
      return nullptr;
    }
    list_.MoveNodeToTail(it->second);
    return it->second;
  }
  
  void Set(const K& key, const V& val)
  {
    auto it = keyNodes_.find(key);
    if (it != keyNodes_.end())
    {
      it->second->val = val;
      list_.MoveNodeToTail(it->second);
      return; 
    }
    Node<K, V>* pNode = new Node<K, V>(key, val);
    keyNodes_.inseert(make_pair(key, pNode));
    list_.AddNode(pNode);
    assert(keyNodes_.size() == list_.size_);
    if (keyNodes_.size() > capacity_)
    {
      MoveMostUnusedNode();
    }
  }

private:
  void MoveMostUnusedNode()
  {
    Node<K, V>* pNode = list_.RemoveHead();
    keyNodes_.erase(pNode->key);
    delete pNode;
  }

private:
  unordered_map<K, Node<K, V>*> keyNodes_;
  DoubleList<K, V> list_;
  const int capacity_;
};
