/*
题目：Add Two Numbers
要求：You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a 
single digit. Add the two numbers and return it as a linked list.
*/

#include <iostream>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;     
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode *head=new ListNode(0);
    if(l1==NULL && l2==NULL) return head;
    int e=0;
    ListNode* l(head);
	//l->val=0;l->next=NULL;
    while(l1!=NULL||l2!=NULL)
    {
        ListNode* data=new ListNode(0);
        if(l1==NULL)
        {
            data->val=(l2->val+e)%10;
            data->next=NULL;
            e=(l2->val+e)/10;
            l->next=data;
            l=l->next;
            l2=l2->next;
        }
        else if(l2==NULL)
        {
            data->val=(l1->val+e)%10;
            data->next=NULL;
            e=(l1->val+e)/10;
            l->next=data;
            l=l->next;
            l1=l1->next;
        }
        else
        {
            data->val=(l1->val+l2->val+e)%10;
            data->next=NULL;
            e=(l1->val+l2->val+e)/10;
            l->next=data;
            l=l->next;
            l2=l2->next;
            l1=l1->next;
        }
    }
    if(e!=0)
    {
        ListNode* data=new ListNode(0);
        data->val=e;
        data->next=NULL;
        l->next=data;
    }
	return head->next;
}

int main()
{
	ListNode* l1=new ListNode(2);
	ListNode* temp0=new ListNode(4);
	l1->next=temp0;
	ListNode* temp1=new ListNode(3);
	l1->next->next=temp1;
	ListNode* l2=new ListNode(5);
	ListNode* temp2=new ListNode(6);
	l2->next=temp2;
	ListNode* temp3=new ListNode(2);
	l2->next->next=temp3;
	ListNode* l=addTwoNumbers(l1, l2);
	system("pause");
	return 0;
}