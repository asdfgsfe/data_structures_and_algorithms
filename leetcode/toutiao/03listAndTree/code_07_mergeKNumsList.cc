//23-合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //原始的方法 归并排序思想 k*(n+m)
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
