#ifndef __GRAPH_H__
#define __GRAPH_H__

struct Graph
{
	unordered_map<int, Node*> nodes; //int��ʵ���ǽڵ��ֵkey ���ݽڵ��ֵ�ҵ���Ӧ�Ľڵ�
	vector<Edge*> edges;
};

#endif //__GRAPH_H__