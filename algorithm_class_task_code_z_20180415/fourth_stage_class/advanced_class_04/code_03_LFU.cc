#include <iostream>
#include <unordered_map>
#include <string>

template <typename K, typename V>
struct Node
{
  K key;
  V val;
  int times;
  Node* up;
  Node* down;

  Node(K k, V v, int t)
    : key(k), val(v), times(t), up(nullptr), down(nullptr)
  {}
};

template<typename K, typename V>
class LFUCache
{
  struct NodeList
  {
    Node<K, V>* head_;
    Node<K, V>* tail_;
    NodeList* last_;
    NodeList* next_;

    NodeList(Node<K, V>* pNode)
      : head_(pNode), tail_(pNode), last_(nullptr), next_(nullptr)
    {}

  bool IsEmpty()
  {
    return head_ == nullptr;
  }

  void AddNodeFromHead(Node<K, V>* pNode)
  {
    assert(head_ != nullptr);
    pNode->down = head_;
    head_->up = pNode;
    head_ = pNode;
  }

  void DeleteNode(Node<K, V>* pNode)
  {
    assert(head_ != nullptr);
    if (head_ == tail_)
    {
      head_ == nullptr;
      tail_ = nullptr;
    }
    else
    {  
      if (head_ == pNode)
      {
        head_ = head_->down;
        head_.up = nullptr;
      }
      else if (tail_ == pNode)
      {
        tail_ = pNode->up;
        pNode->up = nullptr;
      }
      else
      {
        pNode->up->down = pNode->down;
        pNode->down->up = pNode->up;
      }
    }
    pNode->up = nullptr;
    pNode->down = nullptr;
  }
  };

public:
  LFUCache(int capacity)
    : capacity_(capacity), size_(0), pHeadList_(nullptr)
  {}

  void Set(K k, V value)
  {
    const auto it1 = records_.find(k);
    if (it1 != records_.end())
    {
      ++(it1->second->times);
      it1->second->val = value;
      //此处实际是lru的操作 将最近访问的节点放到相同times头部
      //head值竖向链表的头
      MoveToHead(it1->second, pHeads_[it1->second]);
    }
    else
    {
      if (size_ == capacity_)
      {
        const Node<K, V>* pNode = pHeadList_->tail;
        pHeadList_->DeleteNode(pNode);
        ModifyNodeList(pHeadList_);
        records_.erase(pNode->key);
        pHeads_.erase(pNode);
        delete pNode;
        --size_;
      }
      Node<K, V>* pNode = new Node<K, V>(k, value, 1);
      if (pHeadList_ == nullptr)
      {
        pHeadList_= new NodeList(pNode);
      }
      else
      {
        //找到这种times对应的节点,把改节点挂到竖向链表的头部
	if (pHeadList_->head_->times == pNode->times)
        {
          pHeadList_->head_->AddNodeFromHead(pNode);
        }
        else
        {
	//这种times的没有出现，新建一个这种times的竖向链表
	//插入到横向链表的头部
          NodeList* pNewList = new NodeList(pNode);
          pNewList->next = pHeadList_;
          pHeadList_->last = pNewList;
          pHeadList_ = pNewList;
        }
      }
      records_[k] = pNode;
      pHeads_[pNode] = pHeadList_; //这个节点处于哪个横向node
      ++size_;
    }
  }

  const Node<K, V>* Get(K k) const
  {
    const auto it = records_.find(k);
    if (it == records_.end())
    {
      return nullptr;
    }
    ++(it->second->times);
    MoveToHead(it->second, pHeads_[it->second]);
    return it->second;
  }

private:
   //没有移动前pNode节点所在的横向链表的头是pOldNodeList
  void MoveToHead(Node<K, V>* pNode, NodeList* pOldNodeList)
  {
    assert(pNode && pOldNodeList);
    NodeList* pPreList = ModifyNodeList(pOldNodeList) ? pOldNodeList->last : pOldNodeList;
    NodeList* pNextList = pOldNodeList->next_;
    if (pNextList == nullptr)
    {
      NodeList* pNewList = new NodeList(pNode);
      if (pPreList)
      {
        pPreList->next_ = pNewList;
      }
      pNewList->last = pPreList;
      if (pPreList == nullptr)
      {
        pPreList = pNewList;
      }
      pHeads_[pNode] = pNewList;
    }
    else
    {
      if (pNextList->head_->times == pNode->times)
      {
        pNextList->head_->AddNodeFromHead(pNode);
        pHeads_[pNode] = pNextList;
      }
      else
      {
        NodeList* pNewList = new NodeList(pNode);
        if (pPreList)
        {
          pPreList->next_ = pNewList;
        }
        pNewList->last_ = pPreList;
        pNewList->next_ = pNextList;
        pNextList->last = pNewList;
        if (pHeadList_ == pNewList)
        {
          pHeadList_ = pNewList;
        }
        pHeads_[pNode] = pNewList;
      }
    }
  }

  //从NodeList中删除pNodeList节点
  //如果这个链下面只挂一个一个节点，就删除整个竖向链表
  //如果有多个就什么也不操作
  bool ModifyNodeList(NodeList* pNodeList)
  {
    assert(pNodeList);
    if (pNodeList->IsEmpty())
    {
      if (pNodeList == pHeadList_)
      {
        pHeadList_ = pNodeList->next;
        if (pHeadList_)
        {
          pHeadList_->last_ = nullptr;
        }
      }
      else
      {
        pNodeList->last_->next_ = pNodeList->next_;
        if (pNodeList->next_)
        {
          pNodeList->next_->last_ = pNodeList->last;
        }
      }
      return true;
    }
    return false;
  }

private:
  const int capacity_;
  int size_;
  NodeList* pHeadList_;
  std::unordered_map<K, Node<K, V>*> records_;
  std::unordered_map<Node<K, V>*, NodeList*> pHeads_;
};

int main(void)
{
  LFUCache<int, std::string> lfu(3);
  lfu.Set(1, "a");
  lfu.Set(2, "b");
  lfu.Set(3, "c");
  lfu.Get(1);
  lfu.Set(4, "d");
  if (lfu.Get(2) == nullptr)
  {
    std::cout << "yes" << std::endl;
  }
  else
  {
    std::cout << "no" << std::endl;
  }
  std::cout << lfu.Get(4)->val << std::endl;

  return 0;
}
