//感觉方法好多 只要 处理好链表断开的时机就行

ListNode* MergeList(ListNode* l1, ListNode* l2)
{
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    ListNode* head = l1->val <= l2->val ? l1 : l2;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            while (l1->next && l1->next->val <= l2->val)
            {
                l1 = l1->next;
            }
            ListNode* next = l1->next;
            l1->next = l2;
            l1 = next;
        }
        else
        {
            while (l2->next && l2->next->val <= l1->val)
            {
                l2 = l2->next;
            }
            ListNode* next = l2->next;
            l2->next = l1;
            l2 = next;
        }
    }
    return head;
}
