//复制带随机指针的链表


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* node = head;
        while (node) {
            Node* next = node->next;
            Node* tmp = new Node(node->val);
            node->next = tmp;
            tmp->next = next;
            node = next;
        }
        node = head;
        while (node) {
            if (node->random) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        Node* newHead = head->next;
        node = newHead;
        while (head) {
            head->next = node->next;
            node->next = node->next ? node->next->next : nullptr;
            head = head->next;
            node = node->next;
        }
        return newHead;
    }
};
