#ifndef _NODE_H_
#define _NODE_H_

#include <list>

struct Node
{
  int value;
  int in;
  int out;
  std::list<Node*> nexts;
  std::list<Edge*> edges;

  Node(int val)
    : value(val), in(0), out(0)
  {}
};

#endif //_NODE_H_
