Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};

node * solve(node *head, int k, int n)
{
	if(k==1 || !head || !head->next)
		return head;
	int tot_grp=n/k;
	node *temp=head, *newhead=NULL, *prev=NULL, *nn=NULL, *curr_head=NULL, *last_tail=NULL;
	while(temp && tot_grp--)
	{
		curr_head=temp;
		int copy_k = k;
		while(temp && copy_k--)
		{
			nn=temp->next;
			temp->next=prev;
			prev=temp;
			temp=nn;
		}
		if(!newhead)
			newhead=prev;
		if(last_tail)
			last_tail->next=prev;
		last_tail=curr_head;
		if(!tot_grp)
			curr_head->next=NULL;
	}
	return newhead;
}

int main()
{
	int n;cin>>n;
	int k;cin>>k;
	int x;
	cin>>x;
	node *head= new node(x);
	node *tail= head;
	for(int i=1; i<n; ++i)
	{
		cin>>x;
		tail->next=new node(x);
		tail=tail->next;
	}
	head=solve(head, k, n);
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
	return 0;
}