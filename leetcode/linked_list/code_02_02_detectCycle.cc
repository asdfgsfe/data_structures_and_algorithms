//环形链表 II
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/linked-list/jjhf6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* quick = head->next;
        while (quick && quick != slow) {
            slow = slow->next;
            quick = quick->next ? quick->next->next : nullptr;
        }
        if (!quick) {
            return nullptr;
        }
        int size = 1;
        quick = quick->next;
        while (quick != slow) {
            ++size;
            quick = quick->next;
        }
        quick = head;
        for (int i = 0; i < size; ++i) {
            quick = quick->next;
        }
        slow = head;
        while (slow != quick) {
            slow = slow->next;
            quick = quick->next;
        }
        return quick;
    }
};
