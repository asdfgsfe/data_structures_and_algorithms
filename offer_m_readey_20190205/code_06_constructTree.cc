struct BTreeNode
{
  int val;
  BTreeNode* left;
  BTreeNode* right;

  BTreeNode(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

BTreeNode* ReconstrctTree(const vector<int>& preOrder, const vector<int>& inOrder)
{
  if (preOrder.empty() || inOrder.empty())
  {
    return nullptr;
  }
  return Process(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
}

BTreeNode* Process(const vector<int>& preOrder, 
                   int preLeft, 
                   int preRight, 
                   const vector<int>& inOrder,
                   int inLeft,
                   int inRight)
{
  int rootVal = preOrder[preLeft];
  BTreeNode* pRoot = new BTreeNode(rootVal);
  if (preLeft == preRight)
  {
    if (inLeft == inRight && preOrder[preLeft] == inOrder[inLeft])
    {
      return pRoot;
    }
    else
    {
      throw std::exception("vaild input.");
    }
  }
  
  int rootInOrder = inLeft;
  while (rootInOrder <= inRight && inOrder[rootInOrder] != rootVal)
  {
    ++rootOrder;
  }
  if (rootOrder == inRight && inOrder[rootInOrder] != rootVal)
  {
    throw std::exception("vaild input.");
  }
  int leftLength = rootInOrder - inLeft;
  int leftPreOrderRight = preLeft + leftLength;
  if (leftLength > 0)
  {
    pRoot->left = Process(preOrder, preLeft + 1, leftPreOrderRight,
                          inOrder, inLeft, rootInOrder - 1);
  }
  if (preLeft + leftLength < preRight)
  {
    pRoot->right = Process(preOrder, leftPreOrderRight + 1, preRight,
                           inOrder, rootInOrder + 1, inRight);
  }
  return pRoot;
}
