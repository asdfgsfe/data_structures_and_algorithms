vector<int> NextArray(const string& str)
{
  if (str.empty())
  {
    return vector<int>();
  }
  if (str.size() == 1)
  {
    return vector<int>(1, -1);
  }
  vector<int> next(str.size());
  next[0] = -1;
  next[1] = 0;
  int pos = 2;
  int cn = 0;
  while (pos < next.size())
  {
    if (str[pos - 1] == str[cn])
    {
      str[pos++] = ++cn;
    }
    else if (cn > 0)
    {
      cn = next[cn];
    }
    else
    {
      next[pos++] = 0;
    }
  }
  return next;
}


int GetIndexOf(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty())
  {
    return -1;
  }
  vector<int> next = NextArray(s2);
  int i = 0;
  int j = 0;
  while (i < s1.size() && j < s2.size())
  {
    if (s1[i] == s2[j])
    {
      ++i;
      ++j;
    }
    else if (next[j] == -1)
    {
      ++i;
    }
    else
    {
      j = next[j]
    }
  }
  return j == s2.size() ? i - j : -1;
}

string SerializeByPre(const BTreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return string("#!");
  }
  string res = std::to_string(pRoot->val) + "!";
  res += SerializeByPre(pRoot->pLeft);
  res += SerializeByPre(pRoot->pRight);
  return res;
}

//序列化为string kmp算法
bool IsSubBTree1(const BTreeNode* pRoot1, const BTreeNode* pRoot2)
{
  if (pRoot2 == nullptr)
  {
    return true;
  }
  if (pRoot1 == nullptr)
  {
    return false;
  }
  string s1 = SerializeByPre(pRoot1);
  string s2 = SerializeByPre(pRoot2);
  return GetIndexOf(s1, s2) != -1;
}

bool Process(const BTreeNode* pNode1, const BTreeNode* pNode2)
{
  if (pRoot1 == nullptr && pRoot2 == nullptr)
  {
    return true;
  }
  if (pNode1 != pNode2)
  {
    return false;
  }
  return Process(pNode1->pLeft, pNode1->pLeft) && Process(pNode1->pRight, pNode2->pRight);
}

//前序遍历 递归解法 offer方法 效率低 因为有大多节点都需要递归的便利一边
//而序列化只需要递归的搞一遍
bool IsSubBTree2(const BTreeNode* pRoot1, const BTreeNode* pRoot2)
{
  if (pRoot2 == nullptr)
  {
    return true;
  }
  if (pRoot1 == nullptr)
  {
    return false;
  }
  bool isSubTree = false;
  if (pRoo1 == pRoot2)
  {
    isSubTree = Process(pRoot1, pRoot2);
  }
  if (!isSubTree)
  {
    isSubTree = Prcoess(pRoot1->pLeft, pRoot2);
  }
  if (!isSubTree)
  {
    isSubTree = Process(pRoot1->pRight, pRoot2);
  }
  return isSubTree;
}
