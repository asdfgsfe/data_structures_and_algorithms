 �����������е�KС��Ԫ��
����һ����������������дһ������ kthSmallest ���������е� k ����С��Ԫ�ء�

˵����
����Լ��� k ������Ч�ģ�1 �� k �� ����������Ԫ�ظ�����

ʾ�� 1:

����: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
���: 1
ʾ�� 2:

����: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
���: 3
���ף�
��������������������޸ģ�����/ɾ����������������ҪƵ���ز��ҵ� k С��ֵ���㽫����Ż� kthSmallest ������

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