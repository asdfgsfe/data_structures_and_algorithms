二叉搜索树中的搜索
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2     
     / \   
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpsqtv/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
        {
            return nullptr;
        }
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            root = nodes.top();
            nodes.pop();
            if (root->val == val)
            {
                return root;
            }
			//注意下带条件的前序遍历
            if (root->val > val && root->left)
            {
                nodes.push(root->left);
            }
            if (root->val < val && root->right)
            {
                nodes.push(root->right);   
            }
        }
        return nullptr;
    }
};
