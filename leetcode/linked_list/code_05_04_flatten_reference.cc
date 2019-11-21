//��ƽ���༶˫������
//�������һ��˫������������һ����ǰһ��ָ��֮�⣬������һ����ָ�룬����ָ�򵥶���˫������
//��Щ���б������һ�������Լ�������������ƣ����ɶ༶���ݽṹ���������ʾ����ʾ��

//��ƽ���б�ʹ���н������ڵ���˫�����С���������б��һ����ͷ����

//ʾ��:

//����:
// 1---2---3---4---5---6--NULL
//         |
//         7---8---9---10--NULL
//             |
//             11--12--NULL

//���:
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