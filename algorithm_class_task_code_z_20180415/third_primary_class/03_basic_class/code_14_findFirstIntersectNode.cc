#include <iostream>

struct List
{
    int val;
    List* pNext;

    List(int value) : val(value), pNext(NULL) 
    {

    }
};

List* NoLoopNode(List* pHead1, List* pHead2, List* pTailNode)
{
    int len = 0;
    List* pNode1 = pHead1;
    List* pNode2 = pHead2;
    while (pNode1->pNext != pTailNode)
    {
        ++len;
        pNode1 = pNode1->pNext;
    }
    
    while (pNode2->pNext != pTailNode)
    {
        --len;
        pNode2 = pNode2->pNext;
    }

    if (pNode1 != pNode2)
    {
        return NULL;
    }

    pNode1 = len > 0 ? pHead1 : pHead2;
    pNode2 = pNode1 == pHead1 ? pHead2 : pHead1;
    len = len > 0 ? len : -len;
    while (len != 0)
    {
        --len;
        pNode1 = pNode1->pNext;
    }
    
    while (pNode1 != pTailNode && pNode2 != pTailNode)
    {
        if (pNode1 == pNode2)
        {
            return pNode1;
        }

        pNode1 = pNode1->pNext;
        pNode2 = pNode2->pNext;
    }

    return NULL;
}

List* BothLoopNode(List* pHead1, List* pLoopNode1, List* pHead2, List* pLoopNode2)
{
    if (pLoopNode1 == pLoopNode2)
    {
        return NoLoopNode(pHead1, pHead2, pLoopNode1);
    }

    List* pNode = pLoopNode1->pNext;
    while (pNode != pLoopNode1)
    {
        if (pNode == pLoopNode2)
        {
            return pNode;
        }
        pNode = pNode->pNext;
    }

    return NULL;
}

List* LoopNode(List* pHead)
{
    List* pSlowNode = pHead;
    List* pQuickNode = pHead;
    bool isLoop = false;
    

    while (pSlowNode != NULL && pQuickNode != NULL)
    {
        pSlowNode = pSlowNode->pNext;
        pQuickNode = pQuickNode->pNext;
        if (pQuickNode != NULL)
        {
            pQuickNode = pQuickNode->pNext;
        }
        
        if (pSlowNode == pQuickNode)
        {
            isLoop = true;
            break;
        }
    }
    
    if (isLoop)
    {
        pSlowNode = pHead;
        while (pSlowNode != pQuickNode)
        {
            pSlowNode = pSlowNode->pNext;
            pQuickNode = pQuickNode->pNext;
        }

        return pSlowNode;
    }

    return NULL;
}

List* IntersectListNode(List* pHead1, List* pHead2)
{
    if (pHead1 == NULL || pHead2 == NULL)
    {
        return NULL;
    }

    List* pLoopNode1 = LoopNode(pHead1);
    List* pLoopNode2 = LoopNode(pHead2);

    if (pLoopNode1 == NULL && pLoopNode2 == NULL)
    {
        return NoLoopNode(pHead1, pHead2, NULL);
    }

    if (pLoopNode1 != NULL && pLoopNode2 != NULL)
    {
        return BothLoopNode(pHead1, pLoopNode1, pHead2, pLoopNode2);
    }

    return NULL;
}
int main(void)
{
    //1->2->3->4->5->6->7->null
    List* pHead = new List(1);
    pHead->pNext = new List(2);
    pHead->pNext->pNext = new List(3);
    pHead->pNext->pNext->pNext = new List(4);
    pHead->pNext->pNext->pNext->pNext = new List(5);
    pHead->pNext->pNext->pNext->pNext->pNext = new List(6);
    pHead->pNext->pNext->pNext->pNext->pNext->pNext = new List(7);

    //0->9->8->6->7->null
    List* pHead2 = new List(0);
    pHead2->pNext = new List(9);
    pHead2->pNext->pNext = new List(8);
    pHead2->pNext->pNext->pNext = pHead->pNext->pNext->pNext->pNext->pNext; // 8->6
    if (IntersectListNode != NULL)
    {
        std::cout << IntersectListNode(pHead, pHead2)->val << std::endl;
    }
    else
    {
        std::cout << "N" << std::endl;

    }

    //1->2->3->4->5->6->7->4->->->
    pHead = new List(1);
    pHead->pNext = new List(2);
    pHead->pNext->pNext = new List(3);
    pHead->pNext->pNext->pNext = new List(4);
    pHead->pNext->pNext->pNext->pNext = new List(5);
    pHead->pNext->pNext->pNext->pNext->pNext = new List(6);
    pHead->pNext->pNext->pNext->pNext->pNext->pNext = new List(7);
    pHead->pNext->pNext->pNext->pNext->pNext->pNext = pHead->pNext->pNext->pNext; // 7->4

    //0->9->8->2->->->
    pHead2 = new List(0);
    pHead2->pNext = new List(9);
    pHead2->pNext->pNext = new List(8);
    pHead2->pNext->pNext->pNext = pHead->pNext; // 8->2
    if (IntersectListNode != NULL)
    {
        std::cout << IntersectListNode(pHead, pHead2)->val << std::endl;
    }
    else
    {
        std::cout << "N" << std::endl;
    }

    //0->9->8->6->4->5->6->->
    pHead2 = new List(0);
    pHead2->pNext = new List(9);
    pHead2->pNext->pNext = new List(8);
    pHead2->pNext->pNext->pNext = pHead->pNext->pNext->pNext->pNext->pNext; // 8->6
    if (IntersectListNode != NULL)
    {
        std::cout << IntersectListNode(pHead, pHead2)->val << std::endl;    
    }
    else
    {
        std::cout << "N" << std::endl;
    }

    return 0;
}
