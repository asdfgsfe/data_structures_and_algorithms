二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> order;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> curLevel;
            int size = nodes.size();
            while (size-- > 0) {
                root = nodes.front();
                nodes.pop();
                curLevel.emplace_back(root->val);
                if (root->left) {
                    nodes.push(root->left);
                }
                if (root->right) {
                    nodes.push(root->right);
                }
            }
            order.emplace_back(std::move(curLevel));
        }
        return order;
    }
};
