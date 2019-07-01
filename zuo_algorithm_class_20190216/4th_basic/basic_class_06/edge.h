#ifndef __EDGE_H__
#define __EDGE_H__

struct Edge
{
	int weight;
	Node* from;
	Node* to;
	Edge(int w, Node* f, Node* t)
		weight(w), from(f), to(t)
	{}
};

#endif // __EDGE_H__