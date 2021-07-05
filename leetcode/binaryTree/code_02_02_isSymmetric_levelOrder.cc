对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoxzgv/
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


//BFS
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> level;
            int size = nodes.size();
            while(size-- > 0) {
                root = nodes.front();
                nodes.pop();
				//注意这里要将为空的节点也压入队列中 因为空节点也影响镜像的判断
                level.push_back(root ? root->val : 0x80000000);
                if (!root) {
                    continue;
                }
                nodes.push(root->left);
                nodes.push(root->right);
            }
            int l = 0;
            int r = level.size() - 1;
            while (l < r) {
                if (level[l++] != level[r--]) {
                    return false;
                }
            }
        }
        return true;
    }
};
