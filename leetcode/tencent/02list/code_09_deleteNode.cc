 ɾ�������еĽڵ�
���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬�㽫ֻ������Ҫ��ɾ���Ľڵ㡣

����һ������ -- head = [4,5,1,9]�������Ա�ʾΪ:



 

ʾ�� 1:

����: head = [4,5,1,9], node = 5
���: [4,1,9]
����: ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
ʾ�� 2:

����: head = [4,5,1,9], node = 1
���: [4,5,9]
����: ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.
 

˵��:

�������ٰ��������ڵ㡣
���������нڵ��ֵ����Ψһ�ġ�
�����Ľڵ�Ϊ��ĩβ�ڵ㲢��һ���������е�һ����Ч�ڵ㡣
��Ҫ����ĺ����з����κν����

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
    void deleteNode(ListNode* node) {
        if (!node)
        {
            return;
        }
        ListNode* next = node->next;
        node->next = nullptr;
        if (next)
        {
            node->val = next->val;
            node->next = next->next;
        }
        delete next;
        next = nullptr;
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
    void deleteNode(ListNode* node) {
        if (!node || !node->next) {
            return;
        }
        ListNode* next = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete next;
    }
};
