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