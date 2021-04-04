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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        //注意这里可以用快慢指针代替
        int size = 0;
        ListNode* right = head;
        while (right) {
            ++size;
            right = right->next;
        }
        right = head;
        for (int i = 0; i < size / 2 - 1; ++i) {
            right = right->next;
        }
        ListNode* node = right->next;
        right->next = nullptr;
        ListNode* lHead = sortList(head);
        ListNode* rHead = sortList(node);
        return mergeList(lHead, rHead);
    }

    ListNode* mergeList(ListNode* lHead, ListNode* rHead) {
        if (!lHead) {
            return rHead;
        }
        if (!rHead) {
            return lHead;
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (lHead && rHead) {
            ListNode* next = nullptr;
            if (lHead->val <= rHead->val) {
                next = lHead;
                ListNode* tmp = lHead->next;
                lHead->next = nullptr;
                lHead = tmp;
            } else {
                next = rHead;
                ListNode* tmp = rHead->next;
                rHead->next = nullptr;
                rHead = tmp;
            }
            if (!tail) {
                head = tail = next;
            } else {
                tail->next = next;
                tail = tail->next;
            }
        }
        tail->next = lHead != nullptr ? lHead : rHead;
        return head;
    }
};

排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xa262d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
