将有序数组转换为二叉搜索树
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xm5go5/
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
 //这样建成的不仅仅是搜索二叉树 而且还是AVL树
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return nullptr;
		}
		return BSTProcess(nums, 0, nums.size() - 1);
    }

	TreeNode* BSTProcess(const vector<int>& nums, int l, int r)
	{
		if (l > r)
		{
			return nullptr;
		}
		int m = (l + r) / 2;
		TreeNode* root = new TreeNode(nums[m]);
		root->left = BSTProcess(nums, l, m - 1);
		root->right = BSTProcess(nums, m + 1, r);
		return root;
	}
};
