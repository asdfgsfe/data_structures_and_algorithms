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
  ListNode * removeElements(ListNode* head, int val) {
    if (!head)
    {
      return nullptr;
    }
    ListNode* newHead = nullptr;
    ListNode* after = nullptr;
    while (head)
    {
      if (head->val != val)                             
      {
        newHead = !newHead ? head : newHead;
        after = !after ? head : (after->next = head);
      }
      ListNode* next = head->next;
      if (head->val == val)
      {
        delete head;
      }
      head = next;
    }
    if (after)
    {
      after->next = nullptr;
    }
    return newHead;
  }
};
