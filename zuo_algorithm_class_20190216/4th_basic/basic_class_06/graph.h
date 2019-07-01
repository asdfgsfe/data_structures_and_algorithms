#ifndef __GRAPH_H__
#define __GRAPH_H__

struct Graph
{
	unordered_map<int, Node*> nodes;
	vector<Edge*> edges;
};

#endif //__GRAPH_H__