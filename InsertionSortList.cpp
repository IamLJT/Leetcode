/*
题目：Insertion Sort List
要求：Sort a linked list using insertion sort.
*/

#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *pos, *prepos;

ListNode* insertionSortList(ListNode* head) 
{
	int key;
    if(head==NULL || head->next==NULL) return head; 
    ListNode  *i(NULL), *j(NULL);
	ListNode *first = new ListNode(0);
    first->next=head;
    prepos=first->next;
    while(prepos->next!=NULL)
    {
        pos=prepos->next;
        key=pos->val;
        i=first;
        j=i->next;
        while(j!=pos && j->val<pos->val)
        {
            i=i->next;
            j=j->next;
        }
        if(j==pos)
        {
            prepos=prepos->next;
        }
        else
        {
            prepos->next=pos->next;
            i->next=pos;
            pos->next=j;
        }
        if(first->next==pos)
            head=pos;
    }
    return head;
}

int main()
{
	ListNode head(2);
	ListNode next0(1);
	head.next=&next0;
	ListNode next1(3);
	head.next->next=&next1;
	ListNode* head0=insertionSortList(&head);
	for(ListNode* i=head0; i!=NULL; i=i->next)
		cout << i->val << " ";
	cout << endl;
	system("pause");
	return 0;
}