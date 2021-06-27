
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
 //代码稍微优化一点 采用断开重新连接的方法
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = nullptr;
            if (head->val != val) {
                tail = tail ? tail->next = head : head;
                newHead = newHead ? newHead : head;
            } else {
                delete head;
            }
            head = next;
        }
        return newHead;
    }
};

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
