#include <iostream>
#include <stack>

using std::stack;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

void PreOrderRecur(const TreeNode* pRoot)
{
  if (pRoot)
  {
    std::cout << pRoot->val << " ";
    PreOrderRecur(pRoot->left);
    PreOrderRecur(pRoot->right);
  }
}

void InOrderRecur(const TreeNode* pRoot)
{
  if (pRoot)
  {
    InOrderRecur(pRoot->left);
    std::cout << pRoot->val << " ";
    InOrderRecur(pRoot->right);
  }
}

void PosOrderRecur(const TreeNode* pRoot)
{
  if (pRoot)
  {
    PosOrderRecur(pRoot->left);
    PosOrderRecur(pRoot->right);
    std::cout << pRoot->val << " ";
  }
}

void PreOrderUnRecur(const TreeNode* pRoot)
{
  if (pRoot)
  {
    stack<const TreeNode*> st;
    st.push(pRoot);
    while (!st.empty())
    {
      pRoot = st.top();
      st.pop();
      std::cout << pRoot->val << " ";
      if (pRoot->right)
      {
        st.push(pRoot->right);
      }
      if (pRoot->left)
      {
        st.push(pRoot->left);
      }
    }
    std::cout << std::endl;
  }
}

void InOrderUnRecur(const TreeNode* pRoot)
{
  if (pRoot)
  {
    stack<const TreeNode*> st;
    while (!st.empty() || pRoot)
    {
      if (pRoot)
      {
        st.push(pRoot);
        pRoot = pRoot->left;
      }
      else
      {
        pRoot = st.top();
        st.pop();
        std::cout << pRoot->val << " " ;
        pRoot = pRoot->right;
      }
    }
    std::cout << std::endl;
  }
}

void PosOrderUnRecur1(const TreeNode* pRoot)
{
  if (pRoot)
  {
    stack<const TreeNode*> st;
    stack<const TreeNode*> help;
    st.push(pRoot);
    while (!st.empty())
    {
      pRoot = st.top();
      st.pop();
      help.push(pRoot);
      if (pRoot->left)
      {
        st.push(pRoot->left);
      }
      if (pRoot->right)
      {
        st.push(pRoot->right);
      }
    }
    while (!help.empty())
    {
      std::cout << help.top()->val << " ";
      help.pop();
    }
    std::cout << std::endl;
  }
}

void PosOrderUnRecur2(const TreeNode* pRoot)
{
  if (!pRoot)
  {
    return;
  }
  stack<const TreeNode*> st;
  const TreeNode* pLast = nullptr;
  while (pRoot)
  {
    st.push(pRoot);
    pRoot = pRoot->left;
  }
  while (!st.empty())
  {
    pRoot = st.top();
    if (pRoot->right || pLast == pRoot)
    {
      st.pop();
      std::cout << pRoot->val << " ";
      pLast = pRoot;
    }
    else
    {
      pRoot = pRoot->right;
      while (pRoot)
      {
        st.push(pRoot);
        pRoot = pRoot->left;
      }
    }
  }
}

void PosOrderUnRecur3(const TreeNode* pRoot)
{
  if (pRoot)
  {
    stack<const TreeNode*> st;
    st.push(pRoot);
    while (!st.empty())
    {
      const TreeNode* pCurr = st.top();
      if (pCurr->left && pRoot != pCurr->left && pRoot != pCurr->right)
      {
        st.push(pCurr->left);
      }
      else if (pCurr->right && pRoot != pCurr->right)
      {
        st.push(pCurr->right);
      }
      else
      {
        st.pop();
        std::cout << pCurr->val << " ";
        pRoot = pCurr;
      }
    }
    std::cout << std::endl;
  }
}

int main(void)
{
  TreeNode* head = new TreeNode(5);
  head->left = new TreeNode(3);
  head->right = new TreeNode(8);
  head->left->left = new TreeNode(2);
  head->left->right = new TreeNode(4);
  head->left->left->left = new TreeNode(1);
  head->right->left = new TreeNode(7);
  head->right->left->left = new TreeNode(6);
  head->right->right = new TreeNode(10);
  head->right->right->left = new TreeNode(9);
  head->right->right->right = new TreeNode(11);

  // recursive
  std::cout << "==============recursive==============" << std::endl;
  std::cout << "pre-order: " << std::endl;
  PreOrderRecur(head);
  std::cout << std::endl;
  std::cout << "in-order: " << std::endl;
  InOrderRecur(head);
  std::cout << std::endl;
  std::cout << "pos-order: " << std::endl;
  PosOrderRecur(head);
  std::cout << std::endl;
  //
  // unrecursive
  std::cout << "==============unrecursive==============" << std::endl;
  PreOrderUnRecur(head);
  InOrderUnRecur(head);
  PosOrderUnRecur1(head);
  //PosOrderUnRecur2(head);
  PosOrderUnRecur3(head);

  return 0;
}
