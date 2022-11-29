// ListPractice.cpp : Defines the entry point for the application.
//

#include "Functions.h"

using namespace std;



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
