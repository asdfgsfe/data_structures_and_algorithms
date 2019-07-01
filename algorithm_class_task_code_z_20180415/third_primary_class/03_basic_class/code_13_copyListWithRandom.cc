#include <iostream>
#include <unordered_map>

struct List
{
    int val;
    List* pNext;
    List* pRandom;

    List(int value)
        : val(value), pNext(NULL), pRandom(NULL)
    {

    }
};

void PrintLinkerList(List* pHead)
{
    List* pNode = pHead;

    std::cout << "order = [";
    while (pNode != NULL)
    {
        std::cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    std::cout << "]" << std::endl;

    pNode = pHead;
    std::cout << "pRandomom = [";
    while (pNode != NULL)
    {
        if (pNode->pRandom != NULL)
        {
            std::cout << pNode->val << "->" << pNode->pRandom->val << " ";
        }
        else
        {
            std::cout << pNode->val << "->N" << " ";
        }

        pNode = pNode->pNext;
    }
    std::cout << "]" << std::endl;
}


List* CopyListWithpRandom1(List* pHead)
{
    if (pHead == NULL)
    {
        return NULL;
    }

    std::unordered_map<List*, List*> lMap;
    List* pNode = pHead;
    while (pNode != NULL)
    {
        lMap[pNode] = new List(pNode->val);
        pNode = pNode->pNext;
    }

    for (std::unordered_map<List*, List*>::iterator it = lMap.begin(); it != lMap.end(); ++it)
    {
        it->second->pNext = lMap[it->first->pNext];
        if (it->first->pRandom != NULL)
        {
            it->second->pRandom = lMap[it->first->pRandom];
        }
    }

    return lMap[pHead];
}

List* CopyListWithpRandom2(List* pHead)
{
    if (pHead == NULL)
    {
        return NULL;
    }

    List* pNode = pHead;
    while (pNode != NULL)
    {
        List* pNode2 = pNode->pNext;
        pNode->pNext = new List(pNode->val);
        if (pNode->pNext != NULL)
        {
            pNode->pNext->pNext = pNode2;
        }

        pNode = pNode2;
    }

    pNode = pHead;
    while (pNode != NULL)
    {
        if (pNode->pNext != NULL && pNode->pRandom != NULL)
        {
            pNode->pNext->pRandom = pNode->pRandom->pNext;
        }

        pNode = pNode->pNext->pNext;;
    }

    List* pNewpHead = pHead->pNext;
    pNode = pNewpHead;
    while (pHead != NULL && pNode != NULL)
    {
        List* pNode1 = pNode->pNext;
        pHead->pNext= pNode1;
        if (pNode1 != NULL)
        {
            pNode->pNext = pNode1->pNext;
        }

        pHead = pHead->pNext;
        if (pNode != NULL)
        {
            pNode = pNode->pNext;
        }
    }

    return pNewpHead;
}

int main(void)
{
    List* pHead = NULL;
    List* res1 = NULL;
    List* res2 = NULL;
    PrintLinkerList(pHead);
    res1 = CopyListWithpRandom1(pHead);
    PrintLinkerList(res1);
    res2 = CopyListWithpRandom2(pHead);
    PrintLinkerList(res2);
    PrintLinkerList(pHead);
    std::cout << std::endl;

    pHead = new List(1);
    pHead->pNext = new List(2);
    pHead->pNext->pNext = new List(3);
    pHead->pNext->pNext->pNext = new List(4);
    pHead->pNext->pNext->pNext->pNext = new List(5);
    pHead->pNext->pNext->pNext->pNext->pNext = new List(6);

    pHead->pRandom = pHead->pNext->pNext->pNext->pNext->pNext; // 1 -> 6
    pHead->pNext->pRandom = pHead->pNext->pNext->pNext->pNext->pNext; // 2 -> 6
    pHead->pNext->pNext->pRandom = pHead->pNext->pNext->pNext->pNext; // 3 -> 5
    pHead->pNext->pNext->pNext->pRandom = pHead->pNext->pNext; // 4 -> 3
    pHead->pNext->pNext->pNext->pNext->pRandom = NULL; // 5 -> null
    pHead->pNext->pNext->pNext->pNext->pNext->pRandom = pHead->pNext->pNext->pNext; // 6 -> 4

    PrintLinkerList(pHead);                                                
    res1 = CopyListWithpRandom1(pHead);                                  
    PrintLinkerList(res1);                                                  
    res2 = CopyListWithpRandom2(pHead);                                  
    PrintLinkerList(res2);                                                  
    PrintLinkerList(pHead);                                                
    std::cout << std::endl;

    return 0;
}


