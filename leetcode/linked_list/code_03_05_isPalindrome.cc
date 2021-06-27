//回文链表
//请判断一个链表是否为回文链表。
//
//找一个链表的中间节点 注意用快慢指针方法
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
//快慢指针找中间节点
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* quick = head->next;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next ? quick->next->next : nullptr;
        }
        ListNode* newHead = ReverseList(slow, nullptr);
        quick = newHead;
        bool ret = true;
        while (head && newHead) {
            if (head->val != newHead->val) {
                ret = false;
                break;
            }
            head = head->next;
            newHead = newHead->next;
        }
        ReverseList(quick, nullptr);
        return ret;
    }

    ListNode* ReverseList(ListNode* head, ListNode* tail) {
        if (!head || head == tail) {
            return head;
        }
        ListNode* pre = tail;
        while (head != tail) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};



//统计链表数据查找
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
		{
			return true;
		}
		int n = 0;
		ListNode* node = head;
		while (node)
		{
			++n;
			node = node->next;
		}
		n /= 2;
		ListNode* mid = head;
		while (n-- > 0)
		{
			mid = mid->next;
		}
		node = ReverseList(mid);
		mid = node;
		n /= 2;
		bool status = true;
		while (node && head)
		{
			if (node->val != head->val)
			{
				status = false;
				break;
			}
			node = node->next;
			head = head->next;
		}
		ReverseList(mid);
		return status;
	}

	ListNode* ReverseList(ListNode* head)
	{
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* pre = nullptr;
		while (head)
		{
			ListNode* next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};
