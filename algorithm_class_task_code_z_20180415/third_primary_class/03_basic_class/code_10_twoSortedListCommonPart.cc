#include <iostream>

using namespace std;

struct List
{
    List(int val) : val_(val), pNext_(NULL)
    {}

    int val_;
    List* pNext_;
};

void PrintCommonPart(List* pHead1, List* pHead2)
{
    while (pHead1 != NULL && pHead2 != NULL)
    {
        if (pHead1->val_ == pHead2->val_)
        {
            cout << pHead1->val_ << " ";
            pHead1 = pHead1->pNext_;
            pHead2 = pHead2->pNext_;
        }
        else if (pHead1->val_ < pHead2->val_)
        {
            pHead1 = pHead1->pNext_;
        }
        else
        {
            pHead2 = pHead2->pNext_;
        }
    }
    cout << endl;
}

void PrintLinkedList(List* pHead)
{
    while (pHead != NULL)
    {
        cout << pHead->val_ << " ";
        pHead = pHead->pNext_;
    }
    cout << endl;
}

int main(void)
{
    List* pHead1 = new List(2);
    pHead1->pNext_ = new List(3);
    pHead1->pNext_->pNext_ = new List(5);
    pHead1->pNext_->pNext_->pNext_ = new List(6);

    List* pHead2 = new List(1);
    pHead2->pNext_ = new List(2);
    pHead2->pNext_->pNext_ = new List(5);
    pHead2->pNext_->pNext_->pNext_ = new List(7); 
    pHead2->pNext_->pNext_->pNext_->pNext_ = new List(8);

    PrintLinkedList(pHead1);
    PrintLinkedList(pHead2);

    PrintCommonPart(pHead1, pHead2);
    

    return 0;
}
