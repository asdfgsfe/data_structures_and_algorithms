克隆图
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
    public int val;
    public List<Node> neighbors;
}
 

测试用例格式：

简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。

邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。

给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/gmcr6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
	Node * cloneGraph(Node* node) {
		if (!node)
		{
			return nullptr;
		}
		unordered_map<Node*, Node*> nodeToClones;
		Node* clone = new Node(node->val, vector<Node*>());
		nodeToClones[node] = clone;
		queue<Node*> nodes;
		nodes.push(node);
		while (!nodes.empty())
		{
			node = nodes.front();
			nodes.pop();
			for (Node* neighbor : node->neighbors)
			{
				if (!neighbor)
				{
					continue;
				}
				Node* c;
				auto copy = nodeToClones.find(neighbor);
				if (copy == nodeToClones.end())
				{
					c = new Node(neighbor->val, vector<Node*>());
					nodeToClones[neighbor] = c;
                    nodes.push(neighbor);
				}
				else
				{
					c = copy->second;
				}
				nodeToClones[node]->neighbors.emplace_back(c);
			}
		}
		return clone;
	}
};
