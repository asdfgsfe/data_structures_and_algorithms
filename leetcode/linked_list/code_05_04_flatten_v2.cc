//扁平化多级双向链表
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
struct ReturnData {
    Node* h;
    Node* t;

    ReturnData(Node* head, Node* tail) 
        : h(head), t(tail) {}
};

public:
    Node* flatten(Node* head) {
        if (!head) {
            return nullptr;
        }
        return FlattenProcess(head).h;
    }

    ReturnData FlattenProcess(Node* head) {
        Node* node = head;
        Node* tail = nullptr;
        while (node) {
            Node* next = node->next;
            tail = node;
			//将递归函数 放到的while里面
            if (node->child) {
                ReturnData child = FlattenProcess(node->child);
                node->child = nullptr;
                node->next = child.h;
                child.h->prev = node;
                child.t->next = next;
                if (next) {
                    next->prev = child.t;
                }
            }
            node = node->next;
        }
        return ReturnData(head, tail);
    }
};
