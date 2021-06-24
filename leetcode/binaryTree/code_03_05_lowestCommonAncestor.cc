二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xopaih/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return nullptr;
        }
        vector<TreeNode*> path1;
        FindPath(root, p, path1);
        vector<TreeNode*> path2;
        FindPath(root, q, path2);
        int i = 0;
        int j = 0;
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
            ++i;
            ++j;
        }
        return i > 0 ? path1[i - 1] : nullptr;
    }

    bool FindPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (!root) {
            return false;
        }
        path.push_back(root);
        if (root == p) {
            return true;
        }
        if (FindPath(root->left, p, path) || FindPath(root->right, p, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};
