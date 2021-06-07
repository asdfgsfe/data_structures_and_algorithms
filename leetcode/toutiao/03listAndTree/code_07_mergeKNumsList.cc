//23-�ϲ�K����������
�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�

ʾ��:

����:
[
  1->4->5,
  1->3->4,
  2->6
]
���: 1->1->2->3->4->4->5->6

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //ԭʼ�ķ��� �鲢����˼�� k*(n+m)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr;
        }
        while (lists.size() > 1)
        {
            ListNode* rhs = lists.back();
            lists.pop_back();
            ListNode* lhs = lists.back();
            lists.pop_back();
            lists.push_back(MergeTwoList(lhs, rhs));   
        }
        return lists[0];
    }
    
    ListNode* MergeTwoList(ListNode* lhs, ListNode* rhs)
    {
        if (!lhs)
        {
            return rhs;
        }
        if (!rhs)
        {
            return lhs;
        }
        ListNode* curHead = nullptr;
        if (lhs->val <= rhs->val)
        {
            curHead = lhs;
            curHead->next = MergeTwoList(lhs->next, rhs);
        }
        else
        {
            curHead = rhs;
            curHead->next = MergeTwoList(lhs, rhs->next);
        }
        return curHead;
    }
};
