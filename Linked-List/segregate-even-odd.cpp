Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format
Enter N space separated Elements

Constraints
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2
________________________________________________________________________________________________________________________________________________________________________________________


#include<bits/stdc++.h>
using namespace std;

//defining the node for sll
struct node{
	int data;
	node * next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
}*head=NULL;

//function to add a node at the end of sll
node* ie(node *head, int x)
{
	node *temp=new node(x);
	if(head==NULL)
		return temp;
	node *t=head;
	while(t->next)
	{
		t=t->next;
	}
	t->next=temp;
	return head;
}
//function to solve this problem
//make separate list for odd and even and at last connect the head of even list to tail of odd list.
node * solve(node *head)
{
	if(!head || !head->next)
		return head;
	node *temp=head;
	node *eh=NULL;//even list head
	node *oh=NULL;//odd list head
	node *et=NULL;//even list tail
	node *ot=NULL;//odd list tail
	while(temp)
	{
		if(temp->data % 2)
		{
			if(oh==NULL)
			{
				oh=ot=temp;
			}
			else
			{
				ot->next=temp;
				ot=temp;
			}
		}
		else
		{
			if(eh==NULL)
			{
				eh=et=temp;
			}
			else
			{
				et->next=temp;
				et=temp;
			}
		}
		temp=temp->next;
	}
	if(oh == NULL || eh == NULL)//if list only contains odd or only even
		return head;
	ot->next=eh;
	et->next=NULL;
	return oh;
}

int main()
{
	int n;
	cin>>n;
	int x;
	for(int i=0; i<n; ++i)
	{
		cin>>x;
		head=ie(head, x);
	}
	head = solve(head);
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
	return 0;
}