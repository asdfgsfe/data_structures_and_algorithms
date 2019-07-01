#include <assert.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

struct Node
{

};

class UnionFindSet
{
public:
  void MakeSet(const vector<Node*>& nodes)
  {
    fatherMap_.clear();
    sizeMap_.clear();  
    for (auto node : nodes)
    {
      fatherMap_[node] = node;
      sizeMap_[node] = 1;
    }
  }

  bool IsSameSet(Node* pNode1, Node* pNode2)
  {
    if (pNode1 == nullptr || pNode2 == nullptr)
      return false;
    return FindHead(pNode1) == FindHead(pNode2);
  }

  void Union(Node* pNode1, Node* pNode2)
  {
    if (!pNode1 || !pNode2)
    {
      return;
    }
    Node* pFather1 = FindHead(pNode1);
    Node* pFather2 = FindHead(pNode2);
    auto size1 = sizeMap_.find(pNode1);
    assert(size1 != sizeMap_.end());
    auto size2 = sizeMap_.find(pNode2);
    assert(size2 != sizeMap_.end());
    if (size1->second < size2->second)
    {
      fatherMap_[pFather1] = pFather2;
      sizeMap_[pFather2] = size1->second + size2->second;
    }
    else
    {
      fatherMap_[pFather2] = pFather1;
      sizeMap_[pFather1] = size1->second + size2->second;
    }
  }

private:
  Node* FindHead(Node* pNode)
  {
    assert(pNode != nullptr);
    assert(fatherMap_.find(pNode) != fatherMap_.end());
    Node* pFather = fatherMap_[pNode];
    if (pFather != pNode)
    {
      pFather = FindHead(pFather);
    }
    fatherMap_[pNode] = pFather;
    return pFather;
  }
  
  unordered_map<Node*, Node*> fatherMap_;
  unordered_map<Node*, int> sizeMap_;
};

int main(void)
{

  return 0;
}
