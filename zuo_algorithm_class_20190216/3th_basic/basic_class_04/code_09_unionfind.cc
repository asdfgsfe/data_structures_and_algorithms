struct Node
{
  //everyADT
}

class UnionFind
{
public:
  void MakeUnionFind(const vector<Node*>& nodes)
  {
    childFather_.clear();
    rank_.clear();
    for (const auto node : nodes)
    {
      childFather_[node] = node;
      rank_[node] = 1;
    }
  }
  
  Node* FindFather(const Node* pNode)
  {
	assert(father != childFather_.end());
	Node* father = childFather_[pNode];
    if (father != pNode)
    {
      father = FindFather(father);
    }
    childFather[pNode] = father;
    return father;
  }

  void UnionFind(const Node* lth, const Node* rhs)
  {
    if (lth == nullptr || rth == nullptr)
    {
      return;
    }
    auto lFather = FindFather(lth);
    auto rFather = FindFather(rth);
    if (lFather != rFather)
    {
      assert(rank_.find(lFather) != rank_.end());
      assert(rank_.find(rFather) != rank_.end());
      int lRank = rank_[lFather];
      int rRank = rank_[rFather];
      if (lRank < rRank)
      {
        childFather_[lFather] = rFather;
        rank_[rFather] = lRank + rRank;
      }
      else
      {
        childFather_[rFather] = lFather;
        rank_[lFather] = lRank + rRank;
      }
    }
  }
private:
  unordered_map<Node*, Node*> childFather_;
  unordered_map<Node*, int> rank_;
};

