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