#include <iostream>
#include <stack>

using namespace std;

struct List
{
    List(int val) : val_(val), pNext_(NULL)
    {

    }

    int val_;
    List* pNext_;
};

void PrintLinkedList(List* pHead)
{
    cout << "Linked List:[" ;
    while (pHead != NULL)
    {
        cout << pHead->val_ << "->";
        pHead = pHead->pNext_;
    }
    cout << "]" << endl;
}

bool IsParlindromeList1(List* pHead)
{
    stack<int> st;
    List* pNode = pHead;
    
    while (pNode != NULL)
    {
        st.push(pNode->val_);
        pNode = pNode->pNext_;
    }

    while (!st.empty() && pHead != NULL)
    {
        if (st.top() != pHead->val_)
        {
            return false;
        }

        st.pop();
        pHead = pHead->pNext_;
    }

    return true;
}

bool IsParlindromeList2(List* pHead)
{
    stack<int> st;
    List* pQuickNode = pHead;
    List* pSlowNode = pHead;

    while (pQuickNode != NULL && pSlowNode != NULL)
    {
        pSlowNode = pSlowNode->pNext_;
        pQuickNode = pQuickNode->pNext_;
        if (pQuickNode != NULL)
        {
            pQuickNode = pQuickNode->pNext_;
        }
    }

    while (pSlowNode != NULL)
    {
        st.push(pSlowNode->val_);
        pSlowNode = pSlowNode->pNext_;
    }

    while (!st.empty())
    {
        if (st.top() != pHead->val_)
        {
            return false;
        }

        st.pop();
        pHead = pHead->pNext_;
    }

    return true;
}

List* ReverseList(List* pHead)
{
    List* pNode = NULL;
    while (pHead != NULL)
    {
        List* pNext = pHead->pNext_;
        pHead->pNext_ = pNode;

        pNode = pHead;
        pHead = pNext;
    }

    return pNode;
}

List* SearchListMidNode(List* pHead)
{
    List* pQuickNode = pHead;
    List* pSlowNode = pHead;
    while (pQuickNode != NULL && pQuickNode->pNext_ != NULL)
    {
        pSlowNode = pSlowNode->pNext_;
        pQuickNode = pQuickNode->pNext_;

        if (pQuickNode != NULL)
        {
            pQuickNode = pQuickNode->pNext_;
        }
    }

    if (pSlowNode)
        cout << "pSlowNode = " << pSlowNode->val_ << endl;
    return pSlowNode;
}

bool IsParlindromeList3(List* pHead)
{
    if  (pHead == NULL)
    {
        return true;
    }

    bool res = true;
    List* pNode1 = SearchListMidNode(pHead);
    List* pNode2 = pNode1->pNext_;
    pNode1->pNext_ = NULL;

    while (pNode2 != NULL)
    {
        List* pNext = pNode2->pNext_;
        pNode2->pNext_ = pNode1;

        pNode1 = pNode2;
        pNode2 = pNext;
    }

    pNode2 = pNode1;
    while (pNode1 != NULL && pHead != NULL)    
    {
        if (pNode1->val_ != pHead->val_)
        {
            res = false;
            break;
        }

        pNode1 = pNode1->pNext_;
        pHead = pHead->pNext_;
    }

    pNode1 = NULL;
    while (pNode2 != NULL)
    {
        List* pNext = pNode2->pNext_;
        pNode2->pNext_ = pNode1;

        pNode1 = pNode2;
        pNode2 = pNext;

    }

    
    return res;
}


int main(void)
{
    List* pHead = NULL;
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead) 
    << endl;
    PrintLinkedList(pHead);
    cout << endl;

    pHead = new List(1);
    PrintLinkedList(pHead);  
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl; 
    PrintLinkedList(pHead);
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(2);
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl;
    PrintLinkedList(pHead); 
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(1);
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl;
    PrintLinkedList(pHead); 
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(2); 
    pHead->pNext_->pNext_ = new List(3); 
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl; 
    PrintLinkedList(pHead);
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(2);
    pHead->pNext_->pNext_ = new List(1);
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl; 
    PrintLinkedList(pHead); 
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(2);
    pHead->pNext_->pNext_ = new List(3); 
    pHead->pNext_->pNext_->pNext_ = new List(1);
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl;
    PrintLinkedList(pHead);
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(2);
    pHead->pNext_->pNext_ = new List(2);
    pHead->pNext_->pNext_->pNext_ = new List(1);
    PrintLinkedList(pHead);
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl;
    PrintLinkedList(pHead);
    cout << endl;

    pHead = new List(1);
    pHead->pNext_ = new List(2);
    pHead->pNext_->pNext_ = new List(3);
    pHead->pNext_->pNext_->pNext_ = new List(2);
    pHead->pNext_->pNext_->pNext_->pNext_ = new List(1);
    PrintLinkedList(pHead); 
    cout << IsParlindromeList1(pHead) << "|" << IsParlindromeList2(pHead) << "|" << IsParlindromeList3(pHead)
    << endl;
    PrintLinkedList(pHead);
    cout << endl;


    return 0;
}
