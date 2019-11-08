#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <assert.h>

using std::string;
using std::vector;
using std::stack;



//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//查3个case 想法是对的 就是边界条件设置太麻烦了
//思考这种左边怎么样 右边怎么样的思想
 class Solution {
 public:
	 struct ReturnData
	 {
		 TreeNode* head;
		 int lSum;
		 int rSum;
		 int sum;
		 ReturnData(TreeNode* node, int ls , int rs, int s) 
			 : head(node), lSum(ls), rSum(rs), sum(s) 
		 { }
	 };

	 int maxPathSum(TreeNode* root) {
		 if (!root)
		 {
			 return 0x80000000;
		 }
		 int sum = SumProcess(root).sum;
		 sum = std::max(sum, maxPathSum(root->left));
		 sum = std::max(sum, maxPathSum(root->right));
		 return sum;
	 }

	 ReturnData SumProcess(TreeNode* root)
	 {
		 if (!root)
		 {
			 return ReturnData(nullptr, 0x80000000, 0x80000000, 0x80000000);
		 }
		 ReturnData lData = SumProcess(root->left);
		 ReturnData rData = SumProcess(root->right);
		 int lMaxSum = std::max(lData.lSum, lData.rSum); 
		 int lSum = 0;
		 assert(PathSum(root->left, lData.head, lSum));
		 lMaxSum = lMaxSum == 0x80000000 ? lSum /*+ (lData.head ? lData.head->val : 0)*/
										 : lSum + lMaxSum - (lData.head ? lData.head->val : 0);
		 int maxSum = lMaxSum;

		 int rMaxSum = std::max(rData.lSum, rData.rSum);
		 int rSum = 0;
		 assert(PathSum(root->right, rData.head, rSum));
		 rMaxSum = rMaxSum == 0x80000000 ? rSum /*+ (rData.head ? rData.head->val : 0)*/
										 : rSum + rMaxSum - (rData.head ? rData.head->val : 0);
		 maxSum = std::max(maxSum, rMaxSum);
		 
		 maxSum = std::max(maxSum, lMaxSum + rMaxSum);
		 maxSum = std::max(maxSum + root->val, root->val);
		 std::cout << "root=" << root->val 
			 << " root=" << root
			 << " lMaxSum=" << lMaxSum 
			 << " rMaxSum=" << rMaxSum 
			 << " maxSum=" << maxSum 
			 << " lData.lSum=" << lData.lSum
			 << " lData.rSum=" << lData.rSum
			 << " rData.lSum=" << rData.lSum
			 << " rData.rSum=" << rData.rSum << std::endl;
		 return ReturnData(root, lMaxSum, rMaxSum, maxSum);
	 }


	 bool PathSum(TreeNode* from, TreeNode* to, int& sum)
	 {
		 if (from == to)
		 {
			 sum += to ? to->val : 0;
			 return true;
		 }
		 if (!from)
		 {
			 return false;
		 }
		 sum += from->val;
		 if (PathSum(from->left, to, sum))
		 {
			 return true;
		 }
		 if (PathSum(from->right, to, sum))
		 {
			 return true;
		 }
		 sum -= from->val;
		 return false;
	 }
 };


int main(void)
{
	//TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(-2);
	//root->right = new TreeNode(-3);

	//root->left->left = new TreeNode(1);
	//root->left->right = new TreeNode(3);

	//root->right->left = new TreeNode(-2);
	//
	//root->left->left->left = new TreeNode(-1);


	//TreeNode* root = new TreeNode(5);
	//root->left = new TreeNode(4);
	//root->left->left = new TreeNode(11);
	//root->left->left->left = new TreeNode(7);
	//root->left->left->right = new TreeNode(2);

	//root->right = new TreeNode(8);
	//root->right->left = new TreeNode(13);
	//root->right->right = new TreeNode(4);
	//root->right->right->right = new TreeNode(1);


	//TreeNode* root = new TreeNode(-10);
	//root->left = new TreeNode(9);

	//root->right = new TreeNode(20);
	//root->right->left = new TreeNode(15);
	//root->right->right = new TreeNode(7);


	TreeNode* root = new TreeNode(9);
	std::cout << "root(9)=" << root << std::endl;
	root->left = new TreeNode(6);
	std::cout << "root->left(6)=" << root->left << std::endl;

	root->right = new TreeNode(-3);
	std::cout << "root->right(-3)=" << root->right << std::endl;
	root->right->left = new TreeNode(-6);
	std::cout << "root->right->left(-6)=" << root->right->left << std::endl;
	root->right->right = new TreeNode(2);
	std::cout << "root->right->right(2)=" << root->right->right << std::endl;
	root->right->right->left = new TreeNode(2);
	std::cout << "root->right->right->left(2)=" << root->right->right->left << std::endl;
	root->right->right->left->left = new TreeNode(-6);
	std::cout << "root->right->right->left->left(-6)=" << root->right->right->left->left << std::endl;
	root->right->right->left->right = new TreeNode(-6);
	std::cout << "root->right->right->left->right(-6)=" << root->right->right->left->right << std::endl;
	root->right->right->left->left->left = new TreeNode(-6);
	std::cout << "root->right->right->left->left->left(-6)=" << root->right->right->left->left->left << std::endl;

	
	Solution s;
	std::cout << "ANS: " << s.maxPathSum(root) << std::endl;


	return 0;
}