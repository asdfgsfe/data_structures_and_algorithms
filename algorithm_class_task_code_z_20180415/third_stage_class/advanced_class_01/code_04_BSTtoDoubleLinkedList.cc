#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct BinSearchTree
{
  int val;
  BinSearchTree* left;
  BinSearchTree* right;

  BinSearchTree(int value)
    : val(value), left(nullptr), right(nullptr)
  {}
};

void InOrderQueue(BinSearchTree* pNode, queue<BinSearchTree*>& que)
{
  if (pNode == nullptr)
  {
    return;
  }
  InOrderQueue(pNode->left, que);
  que.push(pNode);
  InOrderQueue(pNode->right, que);
}

BinSearchTree* ConvertDoubleLinkedList1(BinSearchTree* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }

  queue<BinSearchTree*> que;
  InOrderQueue(pRoot, que);
  pRoot = que.front();
  que.pop();
  BinSearchTree* prev = pRoot;
  prev->left = nullptr;
  while (!que.empty())
  {
    BinSearchTree* cur = que.front();
    que.pop();
    prev->right = cur;
    cur->left = prev;
    prev = cur;
  }
  prev->right = nullptr;
  return pRoot;
}

BinSearchTree* Process(BinSearchTree* pNode)
{
  if (pNode == nullptr)
  {
    return nullptr;
  }

  BinSearchTree* leftHead = Process(pNode->left);
  BinSearchTree* rightHead = Process(pNode->right);
  pNode->left = nullptr;
  pNode->right = nullptr;
  if (leftHead != nullptr)
  {
    BinSearchTree* leftEnd = leftHead;
    while (leftEnd->right != nullptr)
    {
      leftEnd = leftEnd->right;
    }
    leftEnd->right = pNode;
    pNode->left = leftEnd;
  }
  if (rightHead != nullptr)
  {
    pNode->right = rightHead;
    rightHead->left = pNode;
  }
  return pNode; 
}

BinSearchTree* ConvertDoubleLinkedList2(BinSearchTree* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  return Process(pRoot);
}

vector<BinSearchTree*> Process2(BinSearchTree* pNode)
{
  if (pNode == nullptr)
  {
    return vector<BinSearchTree*> {nullptr, nullptr};
  }

  vector<BinSearchTree*> leftHeads = Process2(pNode->left);
  vector<BinSearchTree*> rightHeads = Process2(pNode->right);
  pNode->left = nullptr;
  pNode->right = nullptr;
  if(leftHeads[1] != nullptr)
  {
    leftHeads[1]->right = pNode;
    pNode->left = leftHeads[1];
  }
  if (rightHeads[0] != nullptr)
  {
    rightHeads[0]->left = pNode;
    pNode->right = rightHeads[0];
  }
  BinSearchTree* left = leftHeads[0] != nullptr ? leftHeads[0] : pNode;
  BinSearchTree* right = rightHeads[1] != nullptr ? rightHeads[1] : pNode;
  return vector<BinSearchTree*> {left, right};
}

BinSearchTree* ConvertDoubleLinkedList3(BinSearchTree* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }

  return Process2(pRoot)[0];
}

BinSearchTree* Process3(BinSearchTree* pNode)
{
  if (pNode == nullptr)
  {
    return nullptr;
  }
  
  BinSearchTree* leftEnd = Process3(pNode->left);
  BinSearchTree* rightEnd = Process3(pNode->right);
  BinSearchTree* leftStart = leftEnd != nullptr ? leftEnd->right : nullptr;
  BinSearchTree* rightStart = rightEnd != nullptr ? rightEnd->right : nullptr;
  if (leftEnd != nullptr && rightEnd != nullptr)
  {
    leftEnd->right = pNode;
    pNode->left = leftEnd;
    rightEnd->right = rightStart;
    rightStart->left = pNode;
    pNode->right = rightStart;
    rightEnd->right = leftStart;
    return rightEnd;
  }
  else if (leftEnd != nullptr)
  {
    leftEnd->right = pNode;
    pNode->left = leftEnd;
    pNode->right = leftStart;
    return pNode;
  }
  else if (rightEnd != nullptr)
  {
    pNode->right = rightStart;
    rightStart->left = pNode;
    rightEnd->right = pNode;
    return rightEnd;
  }
  else 
  {
    pNode->right = pNode;
    return pNode;
  }
}

BinSearchTree* ConvertDoubleLinkedList4(BinSearchTree* pRoot)
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  
  BinSearchTree* pLast = Process3(pRoot);
  pRoot = pLast->right;
  pLast->right = nullptr;
  return pRoot;
}

void InOrderPrint(BinSearchTree* pRoot)
{
  if (pRoot == nullptr)
  {
    return;
  }
  InOrderPrint(pRoot->left);
  std::cout << pRoot->val << " ";
  InOrderPrint(pRoot->right);
}

void PrintBSTInOrder(BinSearchTree* pRoot)
{
  std::cout << "BST in-order: ";
  if (pRoot != nullptr)
  {
    InOrderPrint(pRoot);
  }
  std::cout << std::endl;
}

void PrintDoubleLinkedList(BinSearchTree* pHead)
{
  std::cout << "Double Linked List: ";
  BinSearchTree* pEnd = nullptr;
  while (pHead != nullptr)
  {
    std::cout << pHead->val << " ";
    pEnd = pHead;
    pHead = pHead->right;
  }
  std::cout << "| ";
  while (pEnd != nullptr)
  {
    std::cout << pEnd->val << " ";
    pEnd = pEnd->left;
  }
  std::cout << std::endl;
}

int main(void)
{
  BinSearchTree* head = new BinSearchTree(5);
  head->left = new BinSearchTree(2);
  head->right = new BinSearchTree(9);
  head->left->left = new BinSearchTree(1);
  head->left->right = new BinSearchTree(3);
  head->left->right->right = new BinSearchTree(4);
  head->right->left = new BinSearchTree(7);
  head->right->right = new BinSearchTree(10);
  head->left->left = new BinSearchTree(1);
  head->right->left->left = new BinSearchTree(6);
  head->right->left->right = new BinSearchTree(8);

  PrintBSTInOrder(head);
  head = ConvertDoubleLinkedList1(head);
  PrintDoubleLinkedList(head);

  //FIXME: bug
  head = new BinSearchTree(5);
  head->left = new BinSearchTree(2);
  head->right = new BinSearchTree(9);
  head->left->left = new BinSearchTree(1);
  head->left->right = new BinSearchTree(3);
  head->left->right->right = new BinSearchTree(4);
  head->right->left = new BinSearchTree(7);
  head->right->right = new BinSearchTree(10);
  head->left->left = new BinSearchTree(1);
  head->right->left->left = new BinSearchTree(6);
  head->right->left->right = new BinSearchTree(8);

  PrintBSTInOrder(head);
  head = ConvertDoubleLinkedList2(head);
  PrintDoubleLinkedList(head);




  head = new BinSearchTree(5);
  head->left = new BinSearchTree(2);
  head->right = new BinSearchTree(9);
  head->left->left = new BinSearchTree(1);
  head->left->right = new BinSearchTree(3);
  head->left->right->right = new BinSearchTree(4);
  head->right->left = new BinSearchTree(7);
  head->right->right = new BinSearchTree(10);
  head->left->left = new BinSearchTree(1);
  head->right->left->left = new BinSearchTree(6);
  head->right->left->right = new BinSearchTree(8);

  PrintBSTInOrder(head);
  head = ConvertDoubleLinkedList3(head);
  PrintDoubleLinkedList(head);


  head = new BinSearchTree(5);
  head->left = new BinSearchTree(2);
  head->right = new BinSearchTree(9);
  head->left->left = new BinSearchTree(1);
  head->left->right = new BinSearchTree(3);
  head->left->right->right = new BinSearchTree(4);
  head->right->left = new BinSearchTree(7);
  head->right->right = new BinSearchTree(10);
  head->left->left = new BinSearchTree(1);
  head->right->left->left = new BinSearchTree(6);
  head->right->left->right = new BinSearchTree(8);

  PrintBSTInOrder(head);
  head = ConvertDoubleLinkedList4(head);
  PrintDoubleLinkedList(head);



  return 0;
}
