struct SkipListNode
{
  int val;
  vector<SkipListNode*> nextNodes;

  SkipList(int v)
    : val(v)
  {}
};

class SkipList
{
public:
  SkipList()
    : pRoot_(nullptr), maxLevel_(0), size_(0), kProabaility_(0.5)
  {}

  void Add(int val)
  {
    if (!contains(val))
    {
      ++size_;
      int level = 0;
      while (Math.random() < kProabaility_)
      {
        ++level;
      }
      while (level > maxLevel_)
      {
        pRoot_->nextNodes.push_back(nullptr);
        ++maxLevel_;
      }
      SkipListNode* pNode = new SkipListNode(val);
      SkipListNode* pCur = pRoot_;
      do
      {
        pCur = FindNext(pNode, pCur, level);
        pCur->nextNodes.push_back(pNode);
      }
      while (level_-- > 0);
    }
  }

  void Delete(int val)
  {
    if (contains(val))
    {
      SkipListNode* pDelNode = Find(val);
      --size_;
      int level = maxLevel_;
      do
      {
        pCur = FindNext(val, pCur, level);
        if (pDelNode && pDelNode->nextNodes.size() > level)
        {
          assert(pCur);
          pCur->nextNodes.set(level, pDelNode->nextNodes.get(level));
        }
      }
      while (level-- > 0)
    }
  }

  const SkipList* Root() const
  {
    return pRoot_;
  }

private:
  SkipListNode* Find(int e)
  {
    return FindNext(e, pRoot_, maxLevel_);
  }

  SkipListNode* Find(int e, SkipListNode* pCur, int level)
  {
    do
    {
      pCur = FindNext(e, pCur, level);
    }
    while (level-- > 0);
    return pCur;
  }

  SkipListNode* FindNext(int e, SkipListNode* pCur, int level)
  {
    assert(pCur);
    assert(pCur->nextNodes.size() > level);
    SkipListNode* pNext = pCur->nextNodes[level];
    while (pNext)
    {
      if (LessThan(e, pNext->val))
      {
        break;
      }
      pCur = pNext;
      pNext = pCur->nextNodes[level];
    }
    return pCur;
  }

  bool Contains(int val) const
  {
    SkipListNode* pNode = Find(val);
    return pNode && pNode->val == val;
  }
private:
  SkipListNode* pRoot_;
  int maxLevel_;
  int size_;
  const static float kProabaility_;
}
