

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        stack<TreeNode*> nodes;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                nodes.pop();
                order.push_back(root->val);
                root = root->right;
            }
        }
        return order;
    }
};

//递归
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
        if (!root) {
            return {};
        }
        vector<int> order;
        inorderProcess(root, order);
        return order;
    }

    void inorderProcess(TreeNode* root, vector<int>& order) {
        if (!root) {
            return;
        }
        inorderProcess(root->left, order);
        order.push_back(root->val);
        inorderProcess(root->right, order);
    }
};

//mirros
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
//前序遍历在第一次来到的时候记录
//中序遍历在第一次和第二次来到的时候遍历
//后续只在第二次来到的时候遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> order;
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
					//一定是第二次来到 可以在这个地方记录 同时在下面第二次来到记录
                    //order.push_back(root->val);
                    mostLeft->right = nullptr;
                }
            } /*else {
                order.push_back(root->val); //一定是第一次来到的时候
            }*/
			//可能是第一次来到或者第二次来到 中序需要在第一次来到和第二次来到到时候记录 全部放到这里就行
			order.push_back(root->val);
            root = root->right;
        }
        return order;
    }
};
