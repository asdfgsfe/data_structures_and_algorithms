环形链表 II
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//2种方法 1.如果要用快慢每个走一步 最后判断相等的方法 快慢指针相遇的点必须是链表的最后一个节点 才可以不然会死循环
//2.快慢指针 统计出环上的节点的数量k 从头节点向下走到k节点 然后从头节点和k节点一起走 最后相遇就是环入口节点 本质上两种方法类似 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) //很重要
        {
            return nullptr;
        }
        ListNode* quick = head->next->next; //必须到第三个节点
        ListNode* slow = head->next;//必须第二个
        while (slow != quick)
        {
            if (!slow->next || !quick->next || !quick->next->next) //不能少 防止core
            {
                return nullptr;
            }
            slow = slow->next;
            quick = quick->next->next;
        }
        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
