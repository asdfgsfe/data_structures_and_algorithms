#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* RelocateList(ListNode* head)
{
    if (!head)
    {
        return nullptr;
    }
    int len = 0;
    ListNode* node = head;
    while (node)
    {
        ++len;
        node = node->next;
    }
    if (len < 4)
    {
        return head;
    }
    node = head;
    for (int i = 1; i < len / 2; ++i)
    {
        node = node->next;
    }
    ListNode* rPart = node->next;
    std::cout << "rPart=" << rPart->val << "len=" << len << std::endl;
    node->next = nullptr;
    node = head;
    while (node && rPart)
    {
        ListNode* lNext = node->next;
        ListNode* rNext = rPart->next;
        node->next = rPart;
        if (lNext)
        rPart->next = lNext;
        node = lNext;
        rPart = rNext;
    }
    return head;
}

void Dump(ListNode* head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(void)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Dump(RelocateList(head));

    return 0;
}
