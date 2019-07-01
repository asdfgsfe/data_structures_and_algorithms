#include <iostream>
#include <string>
#include <vector>
//#include <boost/algorithm/string.hpp>

using namespace std;

/**
 * Definition for singly-linked list.
*/ 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

void Dump(const ListNode* head, const string& logo);

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
				std::cout << "head=" << head->val << std::endl;
        ListNode* left = head;
        ListNode* right = head->next;
        while (right && right->next)
				{
					left = left->next;
					right = right->next;
					if (right)
					{
						right = right->next;
					}
				}
				right = left->next;
				left->next = nullptr;
				left = head;
				//std::cout << "left=" << left->val << " rigth=" << right->val << std::endl;
				Dump(left, "left");
				Dump(right, "right");
        left = sortList(left);
        right = sortList(right);
        return Merge(left, right);
    }

	ListNode* Merge(ListNode* lhs, ListNode* rhs)
	{
		if (!lhs)
		{
			return rhs;
		}
		if (!rhs)
		{
			return lhs;
		}
		ListNode* head;
		if (lhs->val <= rhs->val)
		{
			head = lhs;
			head->next = Merge(lhs->next, rhs);
		}
		else
		{
			head = rhs;
			head->next = Merge(lhs, rhs->next);
		}
		return head;
	}
};

void Dump(const ListNode* head, const string& logo)
{
	std::cout << logo << ": ";
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void DumpVec(const vector<int>& nums)
{
	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

int main(void)
{
	//string str;
	//cin >> str;
	//vector<int> nums;
	//boost::split(nums, str, boost::is_any_of(","));
	//DumpVec(nums);
	ListNode* head = new ListNode(-1);
	head->next = new ListNode(5);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(0);
	//head->next->next->next = new ListNode(1);
	//head->next->next->next = new ListNode(1);
	Solution sl;
	
	Dump(sl.sortList(head), "end");
	return 0;
}
