从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
相关标签
树
数组
哈希表
分治
二叉树

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xvix0d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        return BuildProcess(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* BuildProcess(const vector<int>& pre, int pl, int pr,
                        const vector<int>& in, int il, int ir) {
        if (pl > pr || il > ir) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pl]);
        if (pl == pr ) {
            return il == ir ? root : nullptr;
        }
        int l = il;
        while (l <= ir && in[l] != root->val) {
            ++l;
        }
        if (l > ir) {
            return nullptr;
        }
        int leftLen = l - il;
        root->left = BuildProcess(pre, pl + 1, pl + leftLen, in, il, l - 1);
        root->right = BuildProcess(pre, pl + leftLen + 1, pr, in, l + 1, ir);
        return root;
    }
};
