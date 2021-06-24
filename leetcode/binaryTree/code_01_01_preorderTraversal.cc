二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> preorder;
        PreorderProcess(root, preorder);
        return preorder;
    }

    void PreorderProcess(TreeNode* root, vector<int>& preorder) {
        if (!root) {
            return;
        }
        preorder.emplace_back(root->val);
        PreorderProcess(root->left, preorder);
        PreorderProcess(root->right, preorder);
    }
};

//非递归
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> preorder;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            root = nodes.top();
            nodes.pop();
            preorder.emplace_back(root->val);
            if (root->right) {
                nodes.push(root->right);
            }
            if (root->left) {
                nodes.push(root->left);
            }
        }
        return preorder;
    }
};

//mirrors
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> preorder;
        while (root) {
            TreeNode* mostLeft = root->left;
            if (mostLeft) {
                while (mostLeft->right && mostLeft->right != root) {
                    mostLeft = mostLeft->right;
                }
                if (!mostLeft->right) {
					//第一次来到
                    preorder.push_back(root->val);
                    mostLeft->right = root;
                    root = root->left;
                    continue;
                }
                if (mostLeft->right == root) {
                    mostLeft->right = nullptr;
                }
            } else {
				//第一次来到
                preorder.push_back(root->val);
            }
            root = root->right;
        }
        return preorder;
    }
};
