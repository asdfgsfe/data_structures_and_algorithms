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
//�ݹ�
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

//����Ĵ��� ��������
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
		//����ֱ���Ҽ���ʱ�򷵻ؿ� ��Ϊֱ���Ҽ��ĸýڵ��п�¡�ڵ� ��Ҫ�������¡�ڵ�Ҳ���뵽ԭ�������˽ṹ��ȥ
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
//�ǵݹ�
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


//�ǵݹ�dfs�ο���
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
					//�������ﲻ��break ����û�б�Ҫ�ٰ�current ����ջ��
                }
                copyNode.neighbors.add(copyNei***or);
            }
        }
        return copy;
    }
}
