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

 //非递归中序遍历
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root || k < 1) {
            return 0x80000000;
        }
        stack<TreeNode*> nodes;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                nodes.pop();
                if (--k == 0) {
                    return root->val;
                }
                root = root->right;
            }
        }
        return 0x80000000;
    }
};

//递归中序遍历
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
 //递归中序遍历 仅仅只在自己需要的地方处理操作就行
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root || k < 1) {
            return 0x80000000;
        }
        int kth;
        kthSmallProcess(root, k, kth);
        return kth;
    }

    void kthSmallProcess(TreeNode* root, int& k, int& kth) {
        if (!root) {
            return;
        }
        kthSmallProcess(root->left, k, kth);
        if (--k == 0) {
            kth = root->val;
            return;
        }
        kthSmallProcess(root->right, k, kth);
    }
};

















二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

 

示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1
示例 2：


输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
 

 

提示：

树中的节点数为 n 。
1 <= k <= n <= 104
0 <= Node.val <= 104
 

进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？

相关标签
树
二分查找


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xazo8d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
