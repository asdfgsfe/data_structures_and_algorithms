//扁平化多级双向链表
//您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。
//这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

//扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

//示例:

//输入:
// 1---2---3---4---5---6--NULL
//         |
//         7---8---9---10--NULL
//             |
//             11--12--NULL

//输出:
//1-2-3-7-8-11-12-9-10-4-5-6-NULL

class Solution {
public:
    pair<Node *, Node *> flattenHelper(Node *head) 
	{
        if(head == nullptr) 
		{
            return make_pair(nullptr, nullptr);
        }
        pair<Node *, Node *> result = make_pair(head, head);
        while(head) 
		{
            result.second = head;
            if(head->child) 
			{
                pair<Node *, Node *> flattened = flattenHelper(head->child);
                head->child = nullptr;
                Node *next = head->next;
                head->next = flattened.first;
                flattened.first->prev = head;
                flattened.second->next = next;
                if(next) 
				{
                    next->prev = flattened.second;
                }
                head = flattened.second;
            } 
			else
			{
                head = head->next;
            }
        }
        return result;
    }
    Node* flatten(Node* head) {
        pair<Node *, Node *> result = flattenHelper(head);
        return result.first;
    }
};