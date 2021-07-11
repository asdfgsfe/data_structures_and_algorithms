二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。

 
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
        vector<int> values;
        while (root) {
            TreeNode* mostLeft = root->left;
            if (mostLeft) {
                while (mostLeft->right && mostLeft->right != root) {
                    mostLeft = mostLeft->right;
                }
                if (!mostLeft->right) {
                    mostLeft->right = root;
                    root = root->left;
                    continue;
                }
                if (mostLeft->right == root) {
                    mostLeft->right = nullptr;
                }
            }
            values.emplace_back(root->val);
            root = root->right;
        }
        return values;
    }
};
