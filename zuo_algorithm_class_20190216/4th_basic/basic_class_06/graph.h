#ifndef __GRAPH_H__
#define __GRAPH_H__

struct Graph
{
	unordered_map<int, Node*> nodes; //int其实就是节点的值key 依据节点的值找到对应的节点
	vector<Edge*> edges;
};

#endif //__GRAPH_H__