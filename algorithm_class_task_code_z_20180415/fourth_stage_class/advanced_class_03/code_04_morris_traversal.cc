#include <iostream>
#include <string>

using std::string;

struct Node
{
  int val;
  Node* left;
  Node* right;

  Node(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

void MorrisPre(Node* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  Node* pCur = pRoot;
  Node* pMostRight = nullptr;
  while (pCur != nullptr)
  {
    pMostRight = pCur->left;
    if (pMostRight != nullptr)
    {
      while (pMostRight->right != nullptr && pMostRight->right != pCur)
      {
        pMostRight = pMostRight->right;
      }
      if (pMostRight->right == nullptr)
      {
        std::cout << pCur->val << " ";
        pMostRight->right = pCur;
        pCur = pCur->left;
        continue;
      }  
      else
      {
        pMostRight->right = nullptr;
      }
    }
    else
    {
      std::cout << pCur->val << " ";
    }
    pCur = pCur->right;
  }
  std::cout << std::endl;
}

void MorrisIn(Node* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  Node* pCur = pRoot;
  Node* pMostRight = nullptr;
  while (pCur != nullptr)
  {
    pMostRight = pCur->left;
    if (pMostRight != nullptr)
    {
      while (pMostRight->right != nullptr && pMostRight->right != pCur)
      {
        pMostRight = pMostRight->right;
      }
      if (pMostRight->right == nullptr)
      {
        pMostRight->right = pCur;
        pCur = pCur->left;
        continue;
      }
      else
      {
        pMostRight->right = nullptr;
      }
    }
    std::cout << pCur->val << " ";
    pCur = pCur->right;
  }
  std::cout << std::endl;
}

Node* ReverseEdge(Node* pFrom)
{
  Node* pPre = nullptr;
  while (pFrom != nullptr)
  {
    Node* pNext = pFrom->right;
    pFrom->right = pPre;
    pPre = pFrom;
    pFrom = pNext;
  }
  return pPre;
}

void PrintEdge(Node* pNode)
{
  Node* pTail = ReverseEdge(pNode);
  Node* pCur = pTail;
  while (pCur != nullptr)
  {
    std::cout << pCur->val << " ";
    pCur = pCur->right;
  }
  ReverseEdge(pTail);
}

void MorrisPos(Node* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  Node* pCur = pRoot;
  Node* pMostRight = nullptr;
  while (pCur != nullptr)
  {
    pMostRight = pCur->left;
    if (pMostRight != nullptr)
    {
      while (pMostRight->right != nullptr && pMostRight->right != pCur)
      {
        pMostRight = pMostRight->right;
      }
      if (pMostRight->right == nullptr)
      {
        pMostRight->right = pCur;
        pCur = pCur->left;
        continue;
      }
      else
      {
        pMostRight->right = nullptr;
        PrintEdge(pCur->left);
      }
    }
    pCur = pCur->right;
  }
  PrintEdge(pRoot);
  std::cout << std::endl;
}

//帮助理解树遍历的实质
void Process(const Node* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  //point 1
  //std::cout << pRoot->val << " ";
  
  Process(pRoot->left);

  //Point 2
  //std::cout << pRoot->val << " ";
  
  Process(pRoot->right);

  //Point 3
  //std::cout << pRoot->val << " ";
}

string GetSpace(int num)
{
  string space = " ";
  string buf;
  for (int i = 0; i < num; i++) 
  {
    buf.append(space);
  }
  return buf;
}

void PrintInOrder(const Node* pRoot, int height, string to, int len)
{
  if (pRoot == nullptr)
  {
    return;
  }
  PrintInOrder(pRoot->right, height + 1, "v", len);
  string val = to + std::to_string(pRoot->val) + to;
  int lenM = val.length();
  int lenL = (len - lenM) / 2;
  int lenR = len - lenM - lenL;
  val = GetSpace(lenL) + val + GetSpace(lenR);
  std::cout << GetSpace(height * len) <<  val << std::endl;
  PrintInOrder(pRoot->left, height + 1, "^", len);
}

void PrintTree(const Node* pRoot)
{
  std::cout << "Binary Tree: " << std::endl;
  PrintInOrder(pRoot, 0, "H", 17);
  std::cout << std::endl;
}

int main(void)
{
  Node* head = new Node(4);
  head->left = new Node(2);
  head->right = new Node(6);
  head->left->left = new Node(1);
  head->left->right = new Node(3);
  head->right->left = new Node(5);
  head->right->right = new Node(7);
  PrintTree(head);
  MorrisIn(head);
  MorrisPre(head);
  MorrisPos(head);
  PrintTree(head);

  return 0;
}
