#include <iostream>
#include <queue>

using std::queue;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

bool IsCBT(const TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return true;
  }
  queue<const TreeNode*> que;
  que.push(pRoot);
  bool isLeft = false;
  while (!que.empty())
  {
    int size = que.size();
    pRoot = que.front();
    que.pop();
    const TreeNode* pLeft = pRoot->left;
    const TreeNode* pRight = pRoot->right;
    if (pLeft == nullptr && pRight != nullptr)
    {
      return false;
    }
    if (isLeft && (pLeft || pRight))
    {
      return false;
    }
    if (pLeft)
    {
      que.push(pLeft);
    }
    if (pRight)
    {
      que.push(pRight);
    }
    if (!pLeft && !pRight)
    {
      isLeft = true;
    }
  }
  return true;
}

bool IsSBT(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return false;
  }
  TreeNode* pPre = nullptr;
  TreeNode* pCur = pRoot;
  bool res = true;
  while (pCur)
  {
    TreeNode* pNode = pCur->left;
    if (pNode)
    {
      while (pNode->right && pNode->right != pCur)
      {
        pNode = pNode->right;
      }
      if (!pNode->right)
      {
        pNode->right = pCur;
        pCur = pCur->left;
        continue;
      }
      else
      {
        pNode->right = nullptr;
      }
    }
    if (pPre && pPre->val > pCur->val)
    {
      res = false;
    }
    pPre = pCur;
    pCur = pCur->right;
  }
  return res;
}

int main(void)
{
  TreeNode* pRoot = new TreeNode(4);
  pRoot->left = new TreeNode(2);
  pRoot->right = new TreeNode(6);
  pRoot->left->left = new TreeNode(1);
  pRoot->left->right = new TreeNode(3);
  pRoot->right->left = new TreeNode(5);
  std::cout << IsCBT(pRoot) << std::endl;
  std::cout << IsSBT(pRoot) << std::endl;
  
  return 0;
}
