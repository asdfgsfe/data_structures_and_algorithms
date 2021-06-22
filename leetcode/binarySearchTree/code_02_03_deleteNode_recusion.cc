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
		if (root->val == key)
		{
			if (!root->left || !root->right)
			{
				TreeNode* node = root->left ? root->left : root->right;
				delete root;
				return node;
			}
			TreeNode* mostLeft = root->right;
			while (mostLeft->left)
			{
				mostLeft = mostLeft->left;
			}
			root->val = mostLeft->val; //和下面完全是两种方法 找到右子树最左边的值 覆盖当前值 删除右子树最左边的值
			root->right = deleteNode(root->right, mostLeft->val);
		}
		else if (root->val > key)
		{
			root->left = deleteNode(root->left, key);
		}
		else
		{
			root->right = deleteNode(root->right, key);
		}
		return root;
	}
};


//注释
//和上面不一样的地方是直接删除
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        TreeNode* pre = nullptr;
        return DeleteProcess(root, key);
    }

    TreeNode* DeleteProcess(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val < key) {
            root->right = DeleteProcess(root->right, key);
            return root;
        }
        if (root->val > key) {
            root->left = DeleteProcess(root->left, key);
            return root;
        }
        //左子树为空 接到右子树
        if (!root->left) {
            TreeNode* node = root;
            root = root->right;
            node->right = nullptr;
        } else if (!root->right) { //右子树为空 接到左子树
            TreeNode* node = root;
            root = root->left;
            node->left = nullptr;
        } else { //左子树接到右子树最左边
            TreeNode* mostLeft = root->right;
            while (mostLeft->left) {
                mostLeft = mostLeft->left;
            }
            TreeNode* node = root;
            mostLeft->left = root->left;
            root->left = nullptr;
            root = root->right;
            node->right = nullptr;
        }
        return root;
    }
};
