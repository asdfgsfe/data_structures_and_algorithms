从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xo98qt/
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
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
		{
			return nullptr;
		}
		return BuildProcess(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	//用中序和后续遍历序列来做
	TreeNode* BuildProcess(const vector<int>& in, int il, int ir, const vector<int>& post, int pl, int pr)
	{
		if (il > ir || pl > pr)
		{
			return nullptr;
		}
		int rootVal = post[pr];
		TreeNode* root = new TreeNode(rootVal);
		if (pl == pr && il == ir && in[il] == post[pl])
		{
			return root;
		}
		int leftTail = il;
		while (leftTail <= ir && in[leftTail] != rootVal)
		{
			++leftTail;
		}
        if (leftTail > ir)
        {
            return nullptr;
        }
		int leftSize = leftTail - il;
		if (leftSize > 0)
		{
			root->left = BuildProcess(in, il, leftTail - 1, post, pl, pl + leftSize - 1);
		}
		if (ir - il + 1> leftSize)
		{
			root->right = BuildProcess(in, leftTail + 1, ir, post, pl + leftSize, pr - 1);
		}
		return root;
	}
};


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }
        return buildProcess(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

  TreeNode* buildProcess(const vector<int>& in, int iL, int iR, const vector<int>& post, int pL, int pR) {
        if (iL > iR) {
            assert(pL > pR);
            return nullptr;
        }
        TreeNode* root = new TreeNode(post[pR]);
        if (pL == pR) {
            assert(iL == iR && in[iL] == post[pL]);
            return root;
        }
		//这里不用考虑上面那么复杂 直接递归就行
        int rIdx = iL;
        while (rIdx <= iR && in[rIdx] != root->val) {
            ++rIdx;
        }
        if (rIdx > iR) {
            return nullptr;
        }
        int len = rIdx - iL;
        root->left = buildProcess(in, iL, rIdx - 1, post, pL, pL + len - 1);
        root->right = buildProcess(in, rIdx + 1, iR, post, pL + len, pR - 1);
        return root;
    }
};
