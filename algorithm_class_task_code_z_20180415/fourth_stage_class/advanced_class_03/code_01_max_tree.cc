#include <assert.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

struct Tree
{
  Tree* left;
  Tree* right;
  int val;
  Tree(int v)
    : val(v), left(nullptr), right(nullptr)
  {}
};

void PrintMap(const unordered_map<Tree*, Tree*>& nodeMap)
{
  std::cout << "Map:";
  for (auto kv : nodeMap)
  {
    if (kv.first && kv.second)
    {
      std::cout << kv.first->val << "->" << kv.second->val << std::endl;
    }
    else if (kv.first)
    {
      std::cout << kv.first->val << "->" << "null" << std::endl;
    }
    else
    {
      std::cout << "null" << "->" << kv.second->val << std::endl;
    }
  }
}

void PopStackSetMap(stack<Tree*>& st, unordered_map<Tree*, Tree*>& nodeMap)
{
  Tree* pNode = st.top();
  st.pop();
  nodeMap[pNode] = st.empty() ? nullptr : st.top();
}

Tree* MaxTree(const vector<int>& v)
{
  if (v.empty())
  {
    return nullptr;
  }
  vector<Tree*> nodes(v.size());
  for (int i = 0; i < v.size(); ++i)
  {
    nodes[i] = new Tree(v[i]);
  }
  stack<Tree*> st;
  unordered_map<Tree*, Tree*> lBigMap;
  unordered_map<Tree*, Tree*> rBigMap;
  for (int i = 0; i < nodes.size(); ++i)
  {
    assert(nodes[i] != nullptr);
    while (!st.empty() && st.top()->val < nodes[i]->val)
    {
      PopStackSetMap(st, lBigMap);
    }
    st.push(nodes[i]);
  }
  while (!st.empty())
  {
    PopStackSetMap(st, lBigMap);
  }
  for (int i = nodes.size() - 1; i >= 0; --i)
  {
    while (!st.empty() && st.top()->val < nodes[i]->val)
    {
      PopStackSetMap(st, rBigMap);
    }
    st.push(nodes[i]);
  }
  while (!st.empty())
  {
    PopStackSetMap(st, rBigMap);
  }
  PrintMap(lBigMap);
  PrintMap(rBigMap);
  Tree* pRoot = nullptr;
  for (auto node : nodes)
  {
    assert(lBigMap.find(node) != lBigMap.end() && rBigMap.find(node) != rBigMap.end());
    if (lBigMap[node] == nullptr && rBigMap[node] == nullptr)
    {
      pRoot = node;
    }
    else if (lBigMap[node] == nullptr)
    {
      if (rBigMap[node]->left == nullptr)
      {
        rBigMap[node]->left = node;
      }
      else
      {
        rBigMap[node]->right = node;
      }
    }
    else if (rBigMap[node] == nullptr)
    {
      if (lBigMap[node]->left == nullptr)
      {
        lBigMap[node]->left = node;
      }
      else
      {
        lBigMap[node]->right = node;
      }
    }
    else
    {
      Tree* pParent = lBigMap[node]->val < rBigMap[node]->val ? lBigMap[node] : rBigMap[node];
      if (pParent->left == nullptr)
      {
        pParent->left = node;
      }
      else
      {
        pParent->right = node;
      }
    }
  }
  return pRoot;
}

void PrintTreeInOrder(const Tree* pRoot)
{
  if (pRoot != nullptr)
  {
    PrintTreeInOrder(pRoot->left);
    std::cout << pRoot->val << " ";
    PrintTreeInOrder(pRoot->right);
  }
}

void PrintTreePreOrder(const Tree* pRoot)
{
  if (pRoot != nullptr)
  {
    std::cout << pRoot->val << " ";
    PrintTreePreOrder(pRoot->left);
    PrintTreePreOrder(pRoot->right);
  }
}

int main(void)
{
  vector<int> uniqueArr = { 3, 4, 5, 1, 2 };
  Tree* pRoot = MaxTree(uniqueArr);
  PrintTreeInOrder(pRoot);
  std::cout << std::endl;
  PrintTreePreOrder(pRoot);
  return 0;
}
