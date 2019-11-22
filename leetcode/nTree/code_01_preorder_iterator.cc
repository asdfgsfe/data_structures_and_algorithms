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
    vector<int> preorder(Node* root) {
        if (!root)
        {
            {};
        }
        stack<Node*> nodes;
        nodes.push(root);
        vector<int> values;
        while (!nodes.empty())
        {
            root = nodes.top();
            nodes.pop();
            if (!root)//没想明白 为什么会有空指针
            {
                continue;   
            }
            values.emplace_back(root->val);
            const vector<Node*>& children = root->children;
            for (int i = children.size() - 1; i >= 0; --i)
            {
                if (children[i])
                {
                    nodes.push(children[i]);
                }
            }
        }
        return values;
    }
};