/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* sum = nullptr;
        ListNode* tail = nullptr;
        while (l1) {
            tail = tail == nullptr ? new ListNode(l1->val) : tail->next = new ListNode(l1->val);
            sum = sum == nullptr ? tail : sum;
            l1 = l1->next;
        }
        tail = sum;
        while (l2) {
            AddNum(tail, l2->val);
            l2 = l2->next;
            if (l2 && !tail->next) {
                tail->next = new ListNode(0);
            }
            tail = tail->next;
        }
        return sum;
    }

    void AddNum(ListNode* start, int n) {
        while (start) {
            int c = start->val + n;
            start->val = c % 10;
            if (c < 10) {
                break;
            }
            if (!start->next) {
                start->next = new ListNode(0);
            }
            start = start->next;
            n = 1;
        }
    }
};

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
相关标签
递归
链表
数学

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/x55qm1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
