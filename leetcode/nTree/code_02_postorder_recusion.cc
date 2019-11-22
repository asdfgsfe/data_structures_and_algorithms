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
    vector<int> postorder(Node* root) {
        if (!root)
        {
            return {};
        }
        vector<int> values;
        PostProcess(root, values);
        return values;
    }
    
    void PostProcess(Node* root, vector<int>& values)
    {
        if (!root)
        {
            return;
        }
        for (Node* node : root->children)
        {
            PostProcess(node, values);
        }
        values.emplace_back(root->val);
    }
};