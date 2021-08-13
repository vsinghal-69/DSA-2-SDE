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
node * solve(node *head, int k, int n)
{
	if(!head || !head->next)
		return head;
	node *temp=head;
	int c=0;
	node *cnn=NULL;
	k=k%n;//if k>=n, then consider k in a cyclic manner.
	while(temp->next)
	{
		++c;
		if(c==n-k)
		{
			cnn=temp;
		}
		temp=temp->next;
	}
	temp->next=head;
	head=cnn->next;
	cnn->next=NULL;
	return head;
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
	int k;
	cin>>k;
	head = solve(head, k, n);
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
	return 0;
}