/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> values;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.emplace(root);
                root = root->left;
            } else {
                root = nodes.top();
                nodes.pop();
                values.push_back(root->val);
                root = root->right;
            }
        }
        return values;
    }
};

二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。


