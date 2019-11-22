/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
        {
            return {};
        }
        queue<Node*> nodes;
        nodes.push(root);
        vector<vector<int>> levels;
        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> values(size);
            int pos = 0;
            while (size--)
            {
                root = nodes.front();
                nodes.pop();
                values[pos++] = root->val;
                for (Node* node : root->children)
                {
                    if (node)
                    {
                        nodes.push(node);
                    }
                }
            }
            levels.emplace_back(std::move(values));
        }
        return levels;
    }
};