void BFS(const Node* pNode)
{
  if (pNode == nullptr)
  {
    return;
  }
  queue<const Node*> nodes;
  unordered_set<const Node*> unMultiNodes;
  nodes.push(pNode);
  unMultiNodes.insert(pNode);
  while (!nodes.empty())
  {
    int size = que.size();
    while (size--)
    {
      pNode = que.front();
      que.pop();
      std::cout << pNode->val << " ";
      for (const Node* pNext : pNode->nexts)
      {
        if (umMultiNode.find(pNext) == unMultiNode.end())
        {
          que.push(pNext);
          unMultiNodes.insert(pNext);
        }
      }
    }
    std::cout << std::endl;
  }
}
