template<typename K, typename V>
struct Node
{
  K key;
  V val;
  int times;
  Node<K, V>* pUp;
  Node<K, V>* pDown;
  Node() {}
  Node(const K& k, const V& v)
    : key(k), val(v), times(1), pUp(nullptr), pDown(nullptr)
  {}
};

template<typename K, typename V>
class FourWayNode
{
  friend class LFU;
public:
  FourWayNode(){}
  FourWayNode(Node<K, V>* pNode)
    : pYHead_(pNode), pYTail_(pNode), pXPrev_(nullptr), pXNext_(nullptr)
  {}

  void AddNodeToHead(Node<K, V>* pNode)
  {
    if (pNode == nullptr)
    {
      return;
    }
    pNode->pDown = pYHead_;
    assert(pYHead_);
    pYHead_->pUp = pNode;
    pYHead_ = pNode;
  }

  void RemoveNode(Node<K, V>* pNode)
  {
    if (pNode == nullptr)
    {
      return;
    }
    if (pYHead_ == pYTail_)
    {
      pYHead_ = nullptr;
      pYTail_ = nullptr;
      return;
    }
    if (pYHead_ == pNode)
    {
      pYHead_ = pYHead_->pDown;
      pYhead_->pUp = nullptr;
      pNode->pDown = nullptr;
      return;
    }
    if (pYTail_ = pNode)
    {
      pYTail->pUp->pDown = nullptr;
      pYTail->pUp = nullptr;
      return;
    }
    pNode->pUp->pDown = pNode->pDown;
    pNode->pDown->pPre = pNode->pUp;
    pNode->pUp = nullptr;
    pNode->pDown = nullptr;
  }

private:
  Node<K, V>* pYHead_;	//横向链表的Node值
  Node<K, V>* pYTail_;	//横向链表的Node值
  FourWayNode<K, V>* pXPrev_;
  FourWayNode<K, V>* pXNext_;
};

template<typename K, typename V>
class LFU
{
public:
  LFU(){}
  LFU(int c)
    : pXHead_(FoufWayNode(nullptr)), size_(0), capacity_(c)
  {}

  void Set(const K& key, const V& val)
  {
    auto it = keyNodes_.find(key);
    if (it != keyNodes_.end())
    {
      it->second->val = val;
      ++(it->second->times);
      MoveToTail(it->second, pYXHeads_[it->second]);
      return;
    }
    if (size_ == capacity_)
    {
       Node<K, V>* pNode = pXHead_->pYTail_;
       pXHead_->RemoveNode(pNode);
       ModifyXList(pXHead_);
       keyNodes_.erase(pNode->key);
       pYXHeads_.erase(pNode);
       --size_;
       delete pNode;
    }
    Node<K, V>* pNode = new Node<K, V>(key, val, 1);
    if (pXHead_ == nullptr)
    {
      pXHead = new FourWayNode(pNode);
    }
    else
    {
      if (pXHead_->pYHead_->times == pNode->times)
      {
        pXHead_->pYHead_->AddNodeToHead(pNode);
      }
      else
      {
        FourWayNode<K, V> pXNode = new FourWayNode<K, V>(pNode);
        pXNode->pXNext = pXHead_;
        pXHead_->pXPre = pXNode;
        pXHead_ = pXNode;
      }
    }
    keyNodes_[key] = pNode;
    pYXHeads_[pNode] = pXHead_;
    ++size_;
  }

  Node<K, V>* Get(const K& key)
  {
    auto it = keyNodes_.find(key);
    if (it == keyNodes_.end())
    {
      return nullptr;
    }
    ++(it->second->times);
    MoveToTail(it->second, pYXHeads_[it->second]);
    return it->second;
  }

private:
  void MoveToTail(Node<K, V>* pYNode, FourWayNode<K, V>* pXOldNode)
  {
    FourWayNode<K, V>* pXPre = ModifyXList(pXOldNode) ? pXOldNode->pXPre : pXOldNode;
    FourWayNode<K, V>* pXNext = pXOldNode->pXNext;
    if (pXNext == nullptr)
    {
      FourWayNode<K, V>* pXNode = new FourWayNode<K, V>(pYNode);
      if (pXPre)
      {
        pXPre->pXNext = pXNode;
      }
      pXNode->pXPre = pXPre;
      if (pXPre == nullptr)
      {
        pXPre = pXNode;
      }
      pYXHeads_[pYNode] = pXNode;
    }
    else
    {
      if (pXNext->pYHead_->times_ == pYNode->times)
      {
        pXNext->AddNodeToHead(pYNode);
        pYXHeads_[pYNode] = pXNext;
      }
      else
      {
        FourWayNode<K, V>* pXNode = new FourWayNode<K, V>(pYNode);
        if (pXPre)
        {
          pXPre->pXNext = pXNode;
        }
        pXNode->pXPre = pXPre;
        pXNode->pXNext = pXNext;
        pXNext->pXPre = pXNode;
        if (pXHead == nulllptr)
        {
          pXHead = pXNode; 
        }
      }
      pYXHeads_[pYNode] = pXNode;
    }
  }

private:
  FourWayNode<K, V> pXHead_;
  int size_;
  const int capacity_;
  unordered_map<K, Node<K, V>*> keyNodes_; //表示自己在竖向链表的位置
  unordered_map<Node<K, V>*, FourWayNode<K, V>*> pYXHeads_;//自己所在横向链表的位置
};
