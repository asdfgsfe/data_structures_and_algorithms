#include <iostream>
#include <queue>

using std::queue;

struct BTreeNode
{
  int val;
  BTreeNode* pLeft;
  BTreeNode* pRight;

  BTreeNode(int v)
    : val(v), pLeft(nullptr), pRight( nullptr)
  {}
};

void LevelOrderBTree(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  std::queue<const BTreeNode*> que;
  que.push(pRoot);
  while (!que.empty())
  {
    int size = que.size();
    while (size--)
    {
      pRoot = que.front();
      que.pop();
      std::cout << pRoot->val << " ";
      if (pRoot->pLeft)
      {
        que.push(pRoot->pLeft);
      }
      if (pRoot->pRight)
      {
        que.push(pRoot->pRight);
      }
    }
    std::cout << std::endl;
  }
}

int main(void)
{
  BTreeNode* pRoot = new BTreeNode(1);
  pRoot->pLeft = new BTreeNode(2);
  pRoot->pRight = new BTreeNode(3);
  pRoot->pLeft->pLeft = new BTreeNode(4);
  pRoot->pLeft->pRight = new BTreeNode(5);
  pRoot->pRight->pLeft = new BTreeNode(6);
  pRoot->pRight->pRight = new BTreeNode(7);
  LevelOrderBTree(pRoot);

  return 0;
}
