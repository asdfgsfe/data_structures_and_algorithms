#include <iostream>
#include <stack>
#include <unordered_set>
#include "node.h"

void DFS(const Node* pNode)
{
  if (pNode == nullptr)
  {
    return;
  }
  
  std::stack<Node*> nodeStack;
  std::unordered_set<Node*> nodeSet;
  nodeStack.push(pNode);
  nodeSet.insert(pNode);
  std::cout << pNode->val << " ";
  while (!nodeStack.empty())
  {
    pNode = nodeStack.top();
    nodeStack.pop();
    for (auto it = pNode->nexts.begin(); it != pNode->nexts.end(); ++it)
    {
      if (nodeSet.find(*it) == nodeSet.end())
      {
        nodeStack.push(pNode); //pRoot    ���ϼ�node�ڷŻ�ȥ ���˳�����Ҫ �ȷ��ϼ�node �ٷ��Լ�
        nodeStack.push(*it);	//pCurNode
        nodeSet.insert(*it);
        std::cout << *it->val << std::endl;
        break;					//��Ҫ ��֤һ��·�ߵ���
      }
    }
  }
}
