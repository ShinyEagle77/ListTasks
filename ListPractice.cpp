// ListPractice.cpp : Defines the entry point for the application.
//

#include "Functions.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListFunctions
{
public:

	ListNode* middleNode(ListNode* head) // find middle node
	{
		ListNode* slow = head, *fast = head;

		while (fast && fast->next)
		{
			slow = slow->next; fast = fast->next->next;
		}

		return slow;
	}

	static ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		auto const temp = new ListNode();
		temp->next = head;
		const ListNode* faster = temp;
		ListNode* slower = temp;

		for (int i = 1; i <= n; ++i)
		{
			faster = faster->next;
		}

		while (faster->next != nullptr)
		{
			faster = faster->next;
			slower = slower->next;
		}

		slower->next = slower->next->next;

		return temp->next;

	} // 249 5649

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* dummyHead = new ListNode(0);
		ListNode* curr = dummyHead;
		int carry = 0;
		while (l1 != NULL || l2 != NULL || carry != 0) {
			int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}
		return dummyHead->next;
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* dummy, * temp;
		dummy = new ListNode();
		temp = dummy;

		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				temp->next = list1;
				list1 = list1->next;
			}
			else
			{
				temp->next = list2;
				list2 = list2->next;
			}
			temp = temp->next;
		}

		if (list1) temp->next = list1;
		if (list2) temp->next = list2;

		temp = dummy->next;
		delete dummy;
		return temp;
	}

private:

};


int main()
{
	ListNode* l1 = new ListNode(2); // 243 546
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(9);

	ListNode* l2 = new ListNode(5); // 243 546
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(9);

	ListFunctions functions;

}
