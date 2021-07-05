合并K个排序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
相关标签
链表
分治
堆（优先队列）
归并排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xwylvd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
    ListNode* li(vector<ListNode*>& lists) {
        ListNode* base = nullptr;
        for (ListNode* l : lists) {
            base = MergeTwoList2(base, l);
        }
        return base;
    }

    ListNode* MergeTwoList(ListNode* l, ListNode* r) {
        if (!l) {
            return r;
        }
        if(!r) {
            return l;
        }
        if (l->val < r->val) {
            l->next = MergeTwoList(l->next, r);
            return l;
        }
        r->next = MergeTwoList(l, r->next);
        return r;
    }

    ListNode* MergeTwoList2(ListNode* l, ListNode* r) {
        if (!l) {
            return r;
        }
        if (!r) {
            return l;
        }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l && r) {
            if (l->val < r->val) {
                tail = !tail ? l : tail->next = l;
                l = l->next;
            } else {
                tail = !tail ? r : tail->next = r;
                r = r->next;
            }
            head = !head ? tail : head;
        }
		//注意着=这一行容易丢 两个长度不一样 容易断开
        tail->next = l ? l : r;
        return head;
    }
};
