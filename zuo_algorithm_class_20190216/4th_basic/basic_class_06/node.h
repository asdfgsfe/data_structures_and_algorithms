#ifndef __NODE_H__
#define __NODE_H__

struct Node
{
	int val;
	int in;
	int out;
	vetor<Node*> nexts;
	vector<Node*> edges;

	Node(int v)
		: val(v), in(0), out(0)
	{}
};

#endif //__NODE_H__