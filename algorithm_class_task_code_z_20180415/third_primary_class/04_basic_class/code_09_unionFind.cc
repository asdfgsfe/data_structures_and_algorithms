#include <iostream>
#include <unordered_map>
#include <assert.h>

struct Node
{
  int val;
  Node* pFather;
};

struct DisjointSets
{
private:
  std::unordered_map<Node*, Node*> fatherMap;
  std::unordered_map<Node*, int>rankMap

public:
void MakeSet(const std::vector<Node*>& nodes)
{
  fatherMap.clear();
  ranMap.clear();
  for (auto it = ndoes.begin(); it != nodes.end(); ++it)
  {
    fatherMap[*it] = *it;
    rankMap[*it] = 1;
  }
}

Node* FindFather(Node* node)
{
  auto father = node.find(node);
  if (*father != node)
  {
    father = FindFather(*father);    
  }
  fatherMap[nodes] = *father;
  return *father;
}

void Union(Node* pNode1, Node* pNode2)
{
  if (pNode1 == NULL || pNode2 == NULL)
  {
    return ;
  }
  auto father1 = FindFather(pNode1);
  auto father2 = FindFather(pNode2);
  if (*father1 != *father2)
  {
    assert(rankMap.find(pNode1) != rankMap.end());
    assert(rankMap.find(pNode2) != rankMap.end());
    frank1 = rankMap[pNode1];
    frank2 = rankMap[pNode2];
    if (*frank1 <= *frank2)
    {
      fatherMap[pNode1] = pNode2;
      rankMap[pNode2] = *frank1 + *frank2;
    }
    else
    {
      fatherMap[pNode2] = pNode1;
      rankMap[pNode1] = *frank1 + *frank2;
    }
  }
}

};

int main(void)
{

  return 0;
}
