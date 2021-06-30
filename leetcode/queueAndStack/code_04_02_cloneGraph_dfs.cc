/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//递归
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
        {
			return nullptr;
        }
		unordered_map<Node*, Node*> nodeToClones;
		return CloneProcess(node, nodeToClones);
    }

	Node* CloneProcess(Node* node, unordered_map<Node*, Node*>& nodeToClones)
	{
		if (!node)
		{
			return nullptr;
		}
		auto copy = nodeToClones.find(node);
		if (copy != nodeToClones.end())
		{
			return copy->second;
		}
		Node* clone = new Node(node->val, vector<Node*>());
		nodeToClones[node] = clone;
		for (Node* cur : node->neighbors)
		{
			if (cur)
			{
				clone->neighbors.emplace_back(CloneProcess(cur, nodeToClones));
			}
		}
		return clone;
	}
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//错误的代码 留给警告
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        unordered_set<Node*> processed;
        return CloneProcess(node, processed);
    }

    Node* CloneProcess(Node* root, unordered_set<Node*>& processed) {
		//不能直接找见的时候返回空 因为直接找见的该节点有克隆节点 需要将这个克隆节点也加入到原来的拓扑结构中去
        if (!root || processed.count(root)) {
            return nullptr;
        }
        processed.emplace(root);
        Node* node = new Node(root->val);
        for (Node* tmp : root->neighbors) {
            //if (tmp && !processed.count(tmp)) {
                Node* next = CloneProcess(tmp, processed);
                if (next) {
                    node->neighbors.emplace_back(next);
                }
            //}
        }
        return node;
    }
};
//非递归
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
		stack<Node*> nodes;
		nodes.push(node);
		while (!nodes.empty())
		{
			Node* node = nodes.top();
			nodes.pop();
			if (node->neighbors.empty())
			{
				continue;
			}
			auto copyNode = nodeToClones.find(node);
			if (copyNode == nodeToClones.end())
			{
				copyNode->second->neighbors = vector<Node*>();
			}
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
				copyNode->second->neighbors.emplace_back(c);
			}
		}
		return clone;
	}
};


//非递归dfs参考答案
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> resNode2CopyNode = new HashMap<>();
        Stack<Node> stack = new Stack<>();
        stack.push(node);
        Node copy = new Node();
        copy.val = node.val;
        resNode2CopyNode.put(node, copy);
        while (!stack.isEmpty()) {
            Node current = stack.pop();
            List<Node> neighbors = current.neighbors;
            if (neighbors == null) {
                continue;
            }

            Node copyNode = resNode2CopyNode.get(current);
            if (copyNode.neighbors == null) {
                copyNode.neighbors = new LinkedList<>();
            }
            
            for (Node nei***or : neighbors) {
                Node copyNei***or = null;
                if (resNode2CopyNode.containsKey(nei***or)) {
                    copyNei***or = resNode2CopyNode.get(nei***or);
                } else {
                    copyNei***or = new Node();
                    copyNei***or.val = nei***or.val;
                    resNode2CopyNode.put(nei***or, copyNei***or);
                    stack.push(nei***or);
					//由于这里不会break 所以没有必要再把current 存入栈中
                }
                copyNode.neighbors.add(copyNei***or);
            }
        }
        return copy;
    }
}
