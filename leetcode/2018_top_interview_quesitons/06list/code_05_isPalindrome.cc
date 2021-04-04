//不用断开 原先的链表反转 容易造成问题， 得特别小心编译边界条件
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

//从中间开始断开
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* quick = head->next;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }
        quick = slow->next;
        slow->next = nullptr;
        ListNode* right = reverseList(quick);
        quick = right;
        bool ret = true;
        while (head && right) {
            if (head->val != right->val) {
                ret = false;
                break;
            }
            head = head->next;
            right = right->next;
        }
        slow->next = reverseList(right);
        return ret;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};


回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

相关标签
链表
双指针

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xaw0rm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
