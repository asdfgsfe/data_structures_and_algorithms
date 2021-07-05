删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
相关标签
树


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpcnds/
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
	TreeNode * deleteNode(TreeNode* root, int key) {
		if (!root)
		{
			return nullptr;
		}
		TreeNode* keyNode = root;
		TreeNode* pre = nullptr;
		//当作链表来处理 向下遍历
		while (keyNode)
		{
			if (keyNode->val == key)
			{
				break;
			}
			pre = keyNode;
			keyNode = keyNode->val > key ? keyNode->left : keyNode->right;
		}
		//等于删除脸表的某个节点
		if (!pre)
		{
			return Deleting(keyNode);
		}
		if (pre->left && pre->left->val == key)
		{
			pre->left = Deleting(keyNode);
		}
		else
		{
			pre->right = Deleting(keyNode);
		}
		return root;
	}

	//和递归中的方法二一样 只不过递归的方法二采用低柜遍历 而这里由于是搜索二叉树 其实就是单方向遍历 类似于脸表1gg
	TreeNode* Deleting(TreeNode* node)
	{
		if (!node)
		{
			return nullptr;
		}
		if (!node->right)
		{
			TreeNode* ans = node->left;
			delete node;
			return ans;
		}
		TreeNode* mostLeft = node->right;
		while (mostLeft->left)
		{
			mostLeft = mostLeft->left;
		}
		mostLeft->left = node->left;
		mostLeft = node->right;
		delete node;
		return mostLeft;
	}
};
