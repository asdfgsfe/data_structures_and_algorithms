/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        return SumProcess(root, sum);
    }
    
    bool SumProcess(TreeNode* root, int sum)
    {
        assert(root);
        if (!root->left && !root->right)
        {
            return sum - root->val == 0;
        }
        bool status = false;
        if (root->left)
        {
            status = SumProcess(root->left, sum - root->val);
        }
        if (!status && root->right)
        {
            status = SumProcess(root->right, sum - root->val);
        }
        return status;
    }
};

//代码简单一点
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
    bool hasPathSum(TreeNode* root, int targetSum) {
            if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return targetSum - root->val == 0;
        }
        if (root->left && hasPathSum(root->left, targetSum - root->val)) {
            return true;
        }
        if (root->right && hasPathSum(root->right, targetSum - root->val)) {
            return true;
        }
        return false;
    }
};

//错误的方法 因为叶子节点 一定是左子树和右子树同时为空
//下面这种方法 只要左边或者右边为空 就没法判断了
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return SumProcess(root, targetSum);
    }
    bool SumProcess(TreeNode* root, int targetSum) {
        //这个地方无法判断是否为叶子节点
		//关于叶子节点的题目一定要 预先判断是叶子节点
		if (!root) {
            return targetSum == 0;
        }
        targetSum -= root->val;
        if (SumProcess(root->left, targetSum)) {
            return true;
        }
        if (SumProcess(root->right, targetSum)) {
            return true;
        }
        return false;
    }
};
