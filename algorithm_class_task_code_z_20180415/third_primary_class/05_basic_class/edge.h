#ifndef _EDGE_H_
#define _EDGE_H_

#include "Node.h"

struct Edge
{
  int weight;
  Node* from;
  Node* to;
  
  Edge(int w, const Node* f, const Node* t)
    : weight(w), from(f), to(t)
  {}
};

#endif //_EDGE_H_
