#include <iostream>
#include <vector>
#include <algorithm>


struct List
{
    List(int val) : val_(val), pNext_(NULL)
    {

    }

    int val_;
    List* pNext_;
};


void PrintList(List* pHead)
{
    std::cout << "[";
    while (pHead != NULL)
    {
        std::cout << pHead->val_ << " ";
        pHead = pHead->pNext_;
    }
    std::cout << "]" << std::endl;
}

List* ListPartition1(List* pHead, int pivot)
{
    if (pHead == NULL)
    {
        return NULL;
    }

    List* pSmall = NULL;
    List* pTailSmall = NULL;
    List* pEqual = NULL;
    List* pTailEqual = NULL;
    List* pBig = NULL;
    List* pTailBig = NULL;

    while (pHead != NULL)
    {
        List* pNode = pHead->pNext_;
        pHead->pNext_ = NULL;

        if (pHead->val_ == pivot)
        {
            if (pEqual == NULL)
            {
                pEqual = pHead;
            }
            else
            {
                pTailEqual->pNext_ = pHead;
            }
            pTailEqual = pHead;
        }
        else if (pHead->val_ < pivot)
        {
            if (pSmall == NULL)
            {
                pSmall = pHead;
            }
            else
            {
                pTailSmall->pNext_ = pHead;
            }
            pTailSmall = pHead;
        }
        else 
        {
            if (pBig == NULL)
            {
                pBig = pHead;
            }
            else 
            {
                pTailBig->pNext_ = pHead;
            }
            pTailBig = pHead;
        }
        pHead = pNode;
    }

    if (pTailSmall != NULL)
    {
        pTailSmall->pNext_ = pEqual;
        pTailEqual = pTailEqual == NULL ? pTailSmall : pTailEqual;
    }

    if (pTailEqual != NULL)
    {
        pTailEqual->pNext_ = pBig;
    }

    return pSmall != NULL ? pSmall : pEqual != NULL ? pEqual : pBig;
}

void ArrayPartition(std::vector<List*>& v, int pivot)
{
    int small = -1;
    int big = v.size();
    int index = 0;

    while (index != big)
    {
        if (v[index]->val_ == pivot)
        {
            index++;
        }
        else if (v[index]->val_ < pivot)
        {
            std::swap(v[++small], v[index++]);
        }
        else 
        {
            std::swap(v[index], v[--big]);
        }
    }
}


List* ListPartition2(List* pHead, int pivot)
{
    if (pHead == NULL)
    {
        return NULL;
    }

    List* pNode = pHead;
    std::vector<List*> v;
    while (pNode != NULL)
    {
        v.push_back(pNode);
        pNode = pNode->pNext_;
    }

    ArrayPartition(v, pivot);

    //NODE: copy make pre-list change 
    //Error: pHead->val_ = v[i++]->val_
    int i;
    for (i = 1; i < v.size(); ++i)
    {
        v[i-1]->pNext_ = v[i];
    }
    v[i-1]->pNext_ = NULL;

    return v[0];
}

int main(void)
{
    List* pHead = new List(7);
    pHead->pNext_ = new List(9);
    pHead->pNext_->pNext_ = new List(1);
    pHead->pNext_->pNext_->pNext_ = new List(8);
    pHead->pNext_->pNext_->pNext_->pNext_ = new List(5);
    pHead->pNext_->pNext_->pNext_->pNext_->pNext_ = new List(2);
    pHead->pNext_->pNext_->pNext_->pNext_->pNext_->pNext_ = new List(5);

    PrintList(pHead);
    //pHead = ListPartition1(pHead, 5);
    //pHead = ListPartition1(pHead, 4);
    pHead = ListPartition2(pHead, 5);
    PrintList(pHead);

    return 0;
}
