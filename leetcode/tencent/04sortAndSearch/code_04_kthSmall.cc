 二叉搜索树中第K小的元素
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

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
    int kthSmallest(TreeNode* root, int k) {
        if (!root || k <= 0)
        {
            return 0x80000000;
        }
        int kth = 0x80000000;
        stack<TreeNode*> nodes;
        while (root || !nodes.empty())
        {
            if (root)
            {
                nodes.push(root);
                root = root->left;
            }
            else
            {
                --k;
                assert(!nodes.empty());
                root = nodes.top();
                nodes.pop();
                if ( k == 0)
                {
                    kth = root->val;
                    break;
                }
                root = root->right;
            }
        }
        return kth;
    }
};

//递归的中序遍历
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
    int kthSmallest(TreeNode* root, int k) {
        int kthSmallNum;
        InOrderTree(root, kthSmallNum, k);
        return kthSmallNum;
    }

    void InOrderTree(TreeNode* root, int& kthSmallNum, int& k) {
        if (!root) {
            return;
        }
        InOrderTree(root->left, kthSmallNum, k);
        if (--k == 0) {
            kthSmallNum = root->val;
            return;
        }
        InOrderTree(root->right, kthSmallNum, k);
    }
};

