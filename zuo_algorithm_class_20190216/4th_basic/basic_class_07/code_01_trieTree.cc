struct TreeNode
{
  int path;
  int end;
  vector<TreeNode*> pNexts;
  TreeNode()
    : path(0), end(0), pNexts(vector<TreeNode*>(26, nullptr))
  {}
};

struct TrieTree
{
  TreeNode* pRoot;
  TrieTree()
    : pRoot(new TreeNode())
  {}
};

void Insert(const string& word)
{
  if (word.empty())
  {
    return;
  }
  TreeNode* pCurNode = pRoot;
  for (char ch : word)
  {
    int index = ch - 'a';
    if (pCurNode->pNexts[index] == nullptr)
    {
      pCurNode->pNexts[index] = new TreeNode();
    }
    pCurNode = pCurNode->pNexts[index];
    ++pCurNode->path;
  }
  ++pCurNode->end;
}

int Search(const string& word)
{
  if (word.empty())
  {
    return 0;
  }
  TreeNode* pCurNode = pRoot;
  for (char ch : word)
  {
    int index = ch - 'a';
    if (pCurNode->pNexts[index] == nullptr)
    {
      return 0;
    }
    pCurNode = pCurNode->pNext[index];
  }
  return pCurNode->end;
}

void Delete(const string& word)
{
  if (word.empty())
  {
    return;
  }
  if (search(word) == 0)
  {
    return ;
  }
  TreeNode* pCurNode = pRoot;
  for (char ch : word)
  {
    int index = ch - 'a';
    if (--pCurNode->pNexts[index]->path == 0)
    {
      pCurNode->pNexts[index] = nullptr;
      return;
    }
    pCurNode = pCurNode->pNexts[index];
  }
  --pCurNode->end;
}

int PrefixNum(const string& pre)
{
  if (pre.empty())
  {
    return 0;
  }
  TreeNode* pCurNode = pRoot;
  for (char ch : pre)
  {
    int index = ch - 'a';
    if (pCurNode->pNexts[index] == nullptr)
    {
      return 0;
    }
    pCurNode = pCurNode->pNexts[index];
  }
  return pCurNode->path;
}
