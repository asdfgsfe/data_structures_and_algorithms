template<typename KEY, typename VAL>
struct Node
{
	KEY key;
	VAL val;
	int times;
	Node<KEY, VAL>* pUp;
	Node<KEY, VAL>* pDown;
	Node(const KEY& k, const VAL& v)
		: key(k), val(v), times(1), pUp(nullptr), pDown(nullptr)
	{}
};

template<typename KEY, typanem VAl>
class NodeList
{
public:
	NodeList(Node<KEY, VAL>* pNode = nullptr)
		: pHead_(pNode), pTail_(pNode), pPre_(nullptr), pNext_(nullptr)
	{}

	void AddNodeFromHead(Node<KEY, VAL>* pNode)
	{
		if (!pNode)
		{
			return;
		}
		if (!pHead_)
		{
			pHead_ = pNode;
			pTail_ = pNode;
		}
		else
		{
			pNode->pDown = pHead_;
			pHead_->pUp = pNode;
			pHead_ = pNode;
		}
	}

	void RemoveNode(Node<KEY, VAL>* pNode)
	{
		if (!pNode)
		{
			return;
		}
		if (pHead_ == pTail_)
		{
			pHead_ = nullptr;
			pTail_ = nullptr;
			return;
		}
		if (pHead_ == pNode) //到这步至少有2个节点
		{
			pHead_ = pHead_->pDown;
			assert(pHead_);
			pHead_->pUp = nullptr;
			pNode->pDown = nullptr;
			return;
		}
		if (pNode == pTail_)
		{
			pTail = pTail_->pUp;
			assert(pTail_);
			pTail->pDown = nullptr;
			pNode->pUp = nullptr;
			return;
		}
		//走到这里至少有三个节点
		assert(pNode->pUp);
		pNode->pUp->pDown = pNode->pDown;
		assert(pNode->pDown);
		pNode->pDown->pUp = pNode->pUp;
		pNode->pDown = nullptr;
		pNode->pUp = nullptr;
	}
	
	bool Empty() const
	{
		return pHead_ == nullptr;
	}
private:
	Node<KEY, VAL>* pHead_;
	Node<KEY, VAL>* pTail_;
	NodeList<KEY, VAL>* pPre_;
	NodeList<KEY, VAL>* pNext_;
};

template<typename KEY, typename VAL, int SIZE>
class LFU
{
public:
	Node<KEY, VAL>* Get(const KEY& key)
	{
		auto pNode = keyToNodes_.find(key);
		if (pNode == keyToNodes_.end())
		{
			return nullptr;
		}
		auto pCurNodeList = nodeToNodeLists_.find(pNode->second);
		assert(pCurNodeList != nodeToNodeLists_.end());
		++pNode->second->times;
		ToMoveBack(pNode->second, pCurNodeList->second);
		return pNode->second;
	}

	void Set(const KEY& key, const VAl& val)
	{
		auto pNode =  keyToNodes_.find(key);
		if (pNode != keyToNodes.end())
		{
			pNode->second->val = val;
			++pNode->second->times;
			auto pCurNodeList = nodeToNodeLists_.find(pNode->second);
			assert(pCurNodeList != nodeToNodeLists_.end());
			ToMoveBack(pNode->second, pCurNodeList->second);
			return;
		}
		assert(keyToNodes_.size() == nodeToNodeLists_.size());
		if (keyToNodes_.size() == capacity_)
		{
			assert(headList_);
			auto pRemoveNode = headList_->pTail_;
			headList_->RemoveNode(pRemoveNode); //仅仅从链表中删除
			ModiftHeadList(headList_);
			keyToNodes_.erase(pRemoveNode->key);
			nodeToNodeLists_.erase(pRemoveNode);
			delete pRemoveNode;
		}
		Node<KEY, VAL>* pNewNode = new Node<KEY, VAL>(key, val);
		if (!headList_)
		{
			headList_ = new NodeList(pNewNode);
		}
		else
		{
			if (headList_->pHead->times == pNewNode->times)  //竖向链表从头部插入 次数相同的情况下头部最为活跃
			{
				headList_->AddNodeFromHead(pNewNode);
			}
			else
			{
				NodeList<KEY, VAL>* pNewNodeList = new NodeList(pNewNode);
				pNewNodeList->pNext = headList_;
				headList_->pPre = pNewNodeList;
				headList_ = pNewNodeList;
			}
		}
		keyToNodes_[key] = pNewNode;
		nodeToNodeLists_[pNewNode] = headList_;
	}
private:
	void ToMoveBack(Node<KEY, VAL>* pCurNode, NodeList<KEY, VAL>* pOldNodeList)
	{
		assert(pOldNodeList);
		pOldNodeList->RemoveNode(pCurNode);
		NodeList<KEY, VAl>* pPreList = pOldNodeList;
		NodeList<KEY, VAL>* pNextList = nullptr;
		if (ModifyHeadList(pOldNodeList))
		{
			NodeList<KEY, VAl>* pPreList = pOldNodeList->pPre;
			NodeList<KEY, VAL>* pNextList = pOldNodeList->pNext;
			delete pOldNodeList;
		}
		if (!pNextList)
		{
			pNewList = new NodeList(pCurNode);
			pNewList->pPre = pPreList;
			if (pPreList)
			{
				pPreList->pNext = pNewList;
			}
			nodeToNodeLists_[pCurNode] = pNewList;
			return;
		}
		if (pNextList->pHead->times == pCurNode->times)
		{
			pNextList->AddNodeFromHead(pCurNode);
			nodeToNodeLists_[pCurNode] = pNextList;
			return;
		}
		NodeList<KEY, VAL>* pNewNodeList = new NodeList(pCurNode);
		if (pPreList)
		{
			pPreList->pNext = pNewNodeList;
		}
		pNewNodeList->pPre = pPreList;
		pNewNodeList->pNext = pNextList;
		pNextList->pPre = pNewNodeList;
		headList_ = headList_ = pNextList ? pNewNodeList : headList_;
		nodeToNodeLists_[pCurNode] = pNewNodeList;
	}
	bool ModifyHeadList(NodeList<KEY, VAL>* pCurNodeList)
	{
		assert(pCurNodeList);
		if (!pCurNodeList.Empty())
		{
			return false;
		}
		if (headList_ == pCurNodeList)
		{
			headList_ = headList_->pNext;
			if (headList_)
			{
				headList_->pPre = nullptr;
			}
		}
		else
		{
			assert(pCurNodeList->pPre); //走到这里说明至少有2个节点
			pCurNodeList->pPre->pNext = pCurNodeList->pNext;
			if (pCurNodeList->pNext)
			{
				pCurNodeList->pNext->pPre = pCurNodeList->pPre;
			}
		}
		return true;
	}

private:
	const int capacity_;
	unordered_map<KEY, Node<KEY, VAL>*> keyToNodes_;
	unordered_map<Node<KEY, VAL>*, NodeList<KEY, VAL>*> nodeToNodeLists_;
	NodeList<KEY, Node>* headList_;
};