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
        vector<int> order;
        PreorderProcess(root, order);
        return order;
    }
    
    void PreorderProcess(Node* root, vector<int>& order)
    {
        if (!root)
        {
            return;
        }
        order.emplace_back(root->val);
        for (Node* child : root->children)
        {
            PreorderProcess(child, order);
        }
    }
};